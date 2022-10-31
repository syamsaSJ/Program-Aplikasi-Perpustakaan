#include <iostream>

using namespace std;

const int panjangArray = 8;
string dataKategoriAsc[panjangArray] = {"Agama", "Bahasa", "Drama", "Filsafat", "Geografi", "Literatur", "Matematika",
                                        "Psikologi"};
string dataCari;
int ketemu,perbandingan,cari2;
string adminLogin,adminPw, userLogin, userPw;
int pilih, pilihan, pilihAnggota, pilihBuku, pilihData;
bool keluar = false;
char ya_tidak;
const int maksimal_tumpukan = 50;
const int maksantrian_perpustakaan = 50;
const int maksdata = 50;
string data_masuk1, anggota, data_masuk2, data_masuk6, data_masuk4, data_masuk5, data_masuk7;
int data_masuk3;
string data_msk, data_msk1, data_msk2, data_msk3;

struct antrian_perpustakaan{
    int head;
    int tail;
    string mahasiswa[maksantrian_perpustakaan];
};
antrian_perpustakaan perpustakaan;

void nilai_perpustakaan(){
    perpustakaan.head = -1;
    perpustakaan.tail = -1;
}

bool perpustakaan_penuh(){
    if (perpustakaan.tail == maksantrian_perpustakaan - 1){
        return true;
    }else{
        return false;
    }
}

bool perpustakaan_kosong(){
    if(perpustakaan.head == -1 && perpustakaan.tail == -1){
        return true;
    }else{
        return false;
    }
}

void enqueue_perpustakaan(string datamasukan){
    if (perpustakaan_kosong() == true){
        perpustakaan.head = 0;
        perpustakaan.tail = 0;
        perpustakaan.mahasiswa[perpustakaan.tail] = datamasukan;
    }else if (perpustakaan_penuh() == false){
        perpustakaan.tail++;
        perpustakaan.mahasiswa[perpustakaan.tail] = datamasukan;
    }else{
        cout<<"antrian sudah penuh"<<endl;
    }
}

void duqueue_perpustakaan(){
    if (perpustakaan_kosong() == false){
        for (int z = perpustakaan.head; z <= perpustakaan.tail; z++){
            perpustakaan.mahasiswa[z] = perpustakaan.mahasiswa[z+2];
        }
        perpustakaan.tail--;
        cout<<"data sudah terhapus"<<endl;
    }else{
        cout<<"tidak terdapat data pada antrian"<<endl;
    }
}

void tampil_perpustakaan(){
    if (perpustakaan_kosong() == false){
        for (int a = perpustakaan.head; a <= perpustakaan.tail; a++){
            cout<<perpustakaan.mahasiswa[a]<<endl;
        }
        cout<<endl;
    }else{
        cout<<"tidak terdapat data pada antrian"<<endl;
    }
}

struct tumpukan{
    int posisi;
    string judul_buku[maksimal_tumpukan];
    string isbn[maksimal_tumpukan];
    int jmlh_hal[maksimal_tumpukan];
    string bahasa[maksimal_tumpukan];
    string penerbit[maksimal_tumpukan];
    string tahun_terbit[maksimal_tumpukan];
    string letak_buku[maksimal_tumpukan];
};
tumpukan buku;

void inisialisasi(){
    buku.posisi = -1;
}

bool kosong(){
    if(buku.posisi == -1){
        return true;
    }else{
        return false;
    }
}

bool penuh(){
    if(buku.posisi == maksimal_tumpukan - 1){
        return true;
    }else{
        return false;
    }
}

void push_tumpukan(string judul_buku, string isbn, int jmlh_hal, string bahasa, string penerbit, string tahun_terbit, string letak_buku){
    if(kosong() == true){
        buku.posisi++;
        buku.judul_buku[buku.posisi] = judul_buku;
        cout<<"Berhasil memasukkan judul buku      : "<<judul_buku<<endl;
        buku.isbn[buku.posisi] = isbn;
        cout<<"Berhasil memasukkan ISBN            : "<<isbn<<endl;
        buku.jmlh_hal[buku.posisi] = jmlh_hal;
        cout<<"Berhasil memasukkan jumlah halaman  : "<<jmlh_hal<<" Halaman"<<endl;
        buku.bahasa[buku.posisi] = bahasa;
        cout<<"Berhasil memasukkan bahasa          : "<<bahasa<<endl;
        buku.penerbit[buku.posisi] = penerbit;
        cout<<"Berhasil memasukkan penerbit        : "<<penerbit<<endl;
        buku.tahun_terbit[buku.posisi] = tahun_terbit;
        cout<<"Berhasil memasukkan tahun terbit    : "<<tahun_terbit<<endl;
        buku.letak_buku[buku.posisi] = letak_buku;
        cout<<"Berhasil memasukkan letak buku      : "<<letak_buku<<endl;
        cout<<endl;
    }else if(penuh() == false){
        buku.posisi++;
        buku.judul_buku[buku.posisi] = judul_buku;
        cout<<"Berhasil memasukkan judul buku      : "<<judul_buku<<endl;
        buku.isbn[buku.posisi] = isbn;
        cout<<"Berhasil memasukkan ISBN            : "<<isbn<<endl;
        buku.jmlh_hal[buku.posisi] = jmlh_hal;
        cout<<"Berhasil memasukkan jumlah halaman  : "<<jmlh_hal<<" Halaman"<<endl;
        buku.bahasa[buku.posisi] = bahasa;
        cout<<"Berhasil memasukkan bahasa          : "<<bahasa<<endl;
        buku.penerbit[buku.posisi] = penerbit;
        cout<<"Berhasil memasukkan penerbit        : "<<penerbit<<endl;
        buku.tahun_terbit[buku.posisi] = tahun_terbit;
        cout<<"Berhasil memasukkan tahun terbit    : "<<tahun_terbit<<endl;
        buku.letak_buku[buku.posisi] = letak_buku;
        cout<<"Berhasil memasukkan letak buku      : "<<letak_buku<<endl;
         cout<<endl;
    }else{
        cout<<"Tumpukan sudah penuh"<<endl;
    }
}

void pop_tumpukan(){
    if(kosong() == true){
        cout<<"Tumpukan kosong"<<endl;
    }else{
        buku.posisi--;
        cout<<"Data berhasil dihapus"<<endl;
    }
}

void tampil_data(){
    if(kosong() == true){
        cout<<"Tidak ada data"<<endl;
    }else{
        for(int c = buku.posisi; c >= 0; c--){
            cout<<"Judul buku      : "<<buku.judul_buku[c]<<endl;
            cout<<"ISBN            : "<<buku.isbn[c]<<endl;
            cout<<"Jumlah halaman  : "<<buku.jmlh_hal[c]<<" Halaman"<<endl;
            cout<<"Bahasa          : "<<buku.bahasa[c]<<endl;
            cout<<"Penerbit        : "<<buku.penerbit[c]<<endl;
            cout<<"Tahun terbit    : "<<buku.tahun_terbit[c]<<endl;
            cout<<"Letak buku      : "<<buku.letak_buku[c]<<endl<<endl;
        }
    }
}

struct dataMahasiswa{
    dataMahasiswa *prev;
    string data;
    string data1;
    string data2;
    string data3;
    dataMahasiswa *next;
};

dataMahasiswa *head;
dataMahasiswa *tail;
dataMahasiswa *vertex;

void inisialisasiData(){
    head = NULL;
    tail = NULL;
}

bool dataKosong(){
    if(head == NULL && tail == NULL){
        return true;
    }else{
        return false;
    }
}

void tambahData(string dataUser, string dataUser1, string dataUser2, string dataUser3){
    if(dataKosong() == true){
        vertex = new dataMahasiswa;
        vertex->data = dataUser;
        vertex->data1 = dataUser1;
        vertex->data2 = dataUser2;
        vertex->data3 = dataUser3;
        head = vertex;
        tail = vertex;
        head->prev = tail;
        tail->next = head;
    }else{
        vertex = new dataMahasiswa;
        vertex->data = dataUser;
        vertex->data1 = dataUser1;
        vertex->data2 = dataUser2;
        vertex->data3 = dataUser3;
        vertex->next = head;
        head->prev = vertex;
        head = vertex;
        head->prev = tail;
        tail->next = head;
    }
}

void hapusData(){
    if(dataKosong() == true){
        cout<<"Data Kosong...!!!"<<endl<<endl;
    }else{
        cout<<"Data Sudah Dihapus"<<endl<<endl;
        dataMahasiswa *helper;
        helper = head;
        if(head == tail){
            tail->next = NULL;
            head->prev = NULL;
            head = NULL;
            tail = NULL;
            delete helper;
        }else{
            head = head->next;
            head->prev = tail;
            tail->next = head;
            helper->next = NULL;
            delete helper;
        }
    }
}

void tampilDataPeminjaman(){
    if(dataKosong() == true){
        cout<<"Data Kosong...!!!"<<endl;
    }else{
        dataMahasiswa *helper;
        helper = head;
        do{
            cout<<"Nama               : "<<helper->data<<" "<<endl;
            cout<<"NIM                : "<<helper->data1<<" "<<endl;
            cout<<"Judul Buku         : "<<helper->data2<<" "<<endl;
            cout<<"Tanggal Peminjaman : "<<helper->data3<<" "<<endl<<endl;
            helper = helper->next;
        }while(helper != head);
    }
}

void tampilDataPengembalian(){
    if(dataKosong() == true){
        cout<<"Data Kosong...!!!"<<endl;
    }else{
        dataMahasiswa *helper;
        helper = head;
        do{
            cout<<"Nama                 : "<<helper->data<<" "<<endl;
            cout<<"NIM                  : "<<helper->data1<<" "<<endl;
            cout<<"Judul Buku           : "<<helper->data2<<" "<<endl;
            cout<<"Tanggal Pengembalian : "<<helper->data3<<" "<<endl<<endl;
            helper = helper->next;
        }while(helper != head);
    }
}

void interpolationSearch(int panjang){
     int l, h;
     int pos;
     perbandingan = 0;
     ketemu = 0;
     l = 0;
     h = panjang-1;

     do{
        perbandingan++;
        pos = (cari2-l) / (h-l) * (h-l) + l;
        if(dataKategoriAsc[pos] == dataCari){
            ketemu = 1;
        }else if(dataCari < dataKategoriAsc[pos]){
            h = pos-1;
        }else{
            l = pos+1;
        }
    }while(dataCari >= dataKategoriAsc[l] && dataCari <= dataKategoriAsc[h] && ketemu == 0);
}

void tampilDataSearch(){
    for(int i = 0; i < panjangArray; i++){
         if(dataCari == dataKategoriAsc[i]){
            cari2 = i;
            break;
        }else{
            cari2 = panjangArray + 1;
        }
     }
     cout<<endl;
}

void kategoriKebuku (){
    if (dataCari == "Agama"){
        cout<<"Judul          : Agama"<<endl;
        cout<<"ISBN           : 9786230"<<endl;
        cout<<"Jumlah Halaman : 224 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Andi"<<endl;
        cout<<"Tanggal Terbit : 21 Agustus 2019"<<endl;
        cout<<"Letak Buku     : A12"<<endl<<endl;
    }else if (dataCari == "Bahasa"){
        cout<<"Judul          : Prancis"<<endl;
        cout<<"ISBN           : 9786020"<<endl;
        cout<<"Jumlah Halaman : 886 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Pustaka"<<endl;
        cout<<"Tanggal Terbit : 26 Agustus 2016"<<endl;
        cout<<"Letak Buku     : B13"<<endl<<endl;
    }else if (dataCari == "Drama"){
        cout<<"Judul          : Vendetta"<<endl;
        cout<<"ISBN           : 9786024"<<endl;
        cout<<"Jumlah Halaman : 340 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Laksana"<<endl;
        cout<<"Tanggal Terbit : 27 Mei 2019"<<endl;
        cout<<"Letak Buku     : D14"<<endl<<endl;
    }else if (dataCari == "Filsafat"){
        cout<<"Judul          : Filsafat"<<endl;
        cout<<"ISBN           : 9789794"<<endl;
        cout<<"Jumlah Halaman : 280 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Rajawali"<<endl;
        cout<<"Tanggal Terbit : 1 Januari 2009"<<endl;
        cout<<"Letak Buku     : F15"<<endl<<endl;
    }else if (dataCari == "Geografi"){
        cout<<"Judul          : Geografi"<<endl;
        cout<<"ISBN           : 9786028"<<endl;
        cout<<"Jumlah Halaman : 602 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Victory"<<endl;
        cout<<"Tanggal Terbit : 10 Februari 2018"<<endl;
        cout<<"Letak Buku     : G15"<<endl<<endl;
    }else if (dataCari == "Literatur"){
        cout<<"Judul          : sastra"<<endl;
        cout<<"ISBN           : 97860204"<<endl;
        cout<<"Jumlah Halaman : 184 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Elex"<<endl;
        cout<<"Tanggal Terbit : 17 Juli 2017"<<endl;
        cout<<"Letak Buku     : L15"<<endl<<endl;
    }else if (dataCari == "Matematika"){
        cout<<"Judul          : Matematika"<<endl;
        cout<<"ISBN           : 9789797"<<endl;
        cout<<"Jumlah Halaman : 260 Halaman"<<endl;
        cout<<"Bahasa         : Indonesia"<<endl;
        cout<<"Penerbit       : Grafindo"<<endl;
        cout<<"Tanggal Terbit : 1 Oktober 2014"<<endl;
        cout<<"Letak Buku     : M15"<<endl<<endl;
    }else if (dataCari == "Psikologi"){
        cout<<"Judul          : Psychology"<<endl;
        cout<<"ISBN           : 9786646"<<endl;
        cout<<"Jumlah Halaman : 268 Halaman"<<endl;
        cout<<"Bahasa         : Inggris"<<endl;
        cout<<"Penerbit       : Bacabaca"<<endl;
        cout<<"Tanggal Terbit : 29 Desember 2021"<<endl;
        cout<<"Letak Buku     : P15"<<endl<<endl;
    }
}

int main()
{
    system("color B");
    login :
    system("cls");
    cout<<"\tLogin"<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. User"<<endl;
    cout<<"3. Keluar"<<endl;
    cout<<"Silahkan masukkan pilihan (1-3) : ";
    cin>>pilih;
    system("cls");
    if (pilih == 1){
        cout<<"Masukkan ID Admin : ";
        cin>>adminLogin;
        cout<<"Masukkan Password : ";
        cin>>adminPw;
        system("cls");
        menu :
        do{
            cout<<"\t\t"<<"Menu Admin"<<endl;
            cout<<"1. Data Antrian Anggota Perpustakaan"<<endl;
            cout<<"2. Data Buku Perpustakaan"<<endl;
            cout<<"3. Data Peminjaman Buku"<<endl;
            cout<<"4. Data Pengembalian Buku"<<endl;
            cout<<"5. Keluar"<<endl;
            cout<<"silahkan pilih menu (1-5) : ";
            cin>>pilihan;
            system("cls");
            switch (pilihan){
            case 1 :
                nilai_perpustakaan();
                do{
                    cout<<"\t\t"<< "Data Antrian Anggota Perpustakaan"<<endl;
                    cout<<"1. Masukkan data anggota kedalam antrian"<<endl;
                    cout<<"2. Hapus data anggota dari antrian"<<endl;
                    cout<<"3. Tampilkan data antrian"<<endl;
                    cout<<"4. Ke menu utama"<<endl;
                    cout<<"5. Keluar"<<endl;
                    cout<<"Silahkan pilih menu (1-5) : ";
                    cin>>pilihAnggota;
                    switch (pilihAnggota){
                    case 1:
                        cout<<"Silahkan masukkan data anggota : ";
                        cin>>anggota;
                        enqueue_perpustakaan(anggota);
                        cout<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Sampai bertemu kembali"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 2:
                        duqueue_perpustakaan();
                        cout<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 3:
                        tampil_perpustakaan();
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 4:
                        cout<<"Yakin ingin ke menu utama (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            goto menu;
                        }else{
                            system("cls");
                        }
                        break;
                    case 5:
                        cout<<"Yakin ingin keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    default:
                        cout<<"Pilihan tidak tersedia"<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    }
                }while (keluar == false);
                break;

            case 2 :
                inisialisasi();
                do{
                    cout<<"\t\t"<<"Data Buku Perpustakaan"<<endl;
                    cout<<"1. Masukkan data buku"<<endl;
                    cout<<"2. Hapus data buku"<<endl;
                    cout<<"3. Tampilkan data buku"<<endl;
                    cout<<"4. Ke menu utama"<<endl;
                    cout<<"5. Keluar"<<endl;
                    cout<<"Silahkan pilih menu (1-5) : ";
                    cin>>pilihBuku;
                    switch (pilihBuku){
                    case 1 :
                        cout<<"Silahkan masukkan judul buku      : ";
                        cin>>data_masuk1;
                        cout<<"Silahkan masukkan ISBN            : ";
                        cin>>data_masuk2;
                        cout<<"Silahkan masukkan jumlah halaman  : ";
                        cin>>data_masuk3;
                        cout<<"Silahkan masukkan bahasa          : ";
                        cin>>data_masuk4;
                        cout<<"Silahkan masukkan penerbit        : ";
                        cin>>data_masuk5;
                        cout<<"Silahkan masukkan tanggal terbit  : ";
                        cin>>data_masuk6;
                        cout<<"Silahkan masukkan letak buku      : ";
                        cin>>data_masuk7;
                        cout<<endl;
                        push_tumpukan(data_masuk1, data_masuk2, data_masuk3, data_masuk4, data_masuk5, data_masuk6, data_masuk7);
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Sampai bertemu kembali"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 2 :
                        pop_tumpukan();
                        cout<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 3 :
                        tampil_data();
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 4 :
                        cout<<"Yakin ingin ke menu utama (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            goto menu;
                        }else{
                            system("cls");
                        }
                        break;
                    case 5 :
                        cout<<"Yakin anda ingin keluar dari menu (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    default :
                        cout<<"Pilihan tidak tersedia"<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    }
                }while (keluar == false);
                break;

            case 3 :
                inisialisasiData();
                do{
                    cout<<"\t\t"<<"Data Peminjaman Buku"<<endl;
                    cout<<"1. Tambah data"<<endl;
                    cout<<"2. Hapus data"<<endl;
                    cout<<"3. Tampil data"<<endl;
                    cout<<"4. Ke menu utama"<<endl;
                    cout<<"5. Keluar"<<endl;
                    cout<<"Silahkan pilih menu (1-5) : ";
                    cin>>pilihData;
                    cout<<endl;
                    switch (pilihData){
                    case 1 :
                        cout<<"Silahkan masukkan nama mahasiswa     : ";
                        cin>>data_msk;
                        cout<<"Silahkan masukkan NIM mahasiswa      : ";
                        cin>>data_msk1;
                        cout<<"Silahkan masukkan Judul Buku         : ";
                        cin>>data_msk2;
                        cout<<"Silahkan masukkan Tanggal peminjaman : ";
                        cin>>data_msk3;
                        tambahData(data_msk, data_msk1, data_msk2, data_msk3);
                        cout<<endl;
                        cout<<"Data Sudah Ditambahkan"<<endl<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Sampai bertemu kembali"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 2 :
                        hapusData();
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 3 :
                        tampilDataPeminjaman();
                        cout<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 4 :
                        cout<<"Yakin ingin ke menu utama (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            goto menu;
                        }else{
                            system("cls");
                        }
                        break;
                    case 5 :
                        cout<<"Yakin anda ingin keluar dari menu (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    default:
                        cout<<"Pilihan tidak tersedia"<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    }
                }while (keluar == false);
                break;

            case 4 :
                inisialisasiData();
                do{
                    cout<<"\t\t"<<"Data Pengembalian Buku"<<endl;
                    cout<<"1. Tambah data"<<endl;
                    cout<<"2. Hapus data"<<endl;
                    cout<<"3. Tampil data"<<endl;
                    cout<<"4. Ke menu utama"<<endl;
                    cout<<"5. Keluar"<<endl;
                    cout<<"Silahkan pilih menu (1-5) : ";
                    cin>>pilihData;
                    cout<<endl;
                    switch (pilihData){
                    case 1 :
                        cout<<"Silahkan masukkan nama mahasiswa       : ";
                        cin>>data_msk;
                        cout<<"Silahkan masukkan NIM mahasiswa        : ";
                        cin>>data_msk1;
                        cout<<"Silahkan masukkan Judul Buku           : ";
                        cin>>data_msk2;
                        cout<<"Silahkan masukkan Tanggal pengembalian : ";
                        cin>>data_msk3;
                        tambahData(data_msk, data_msk1, data_msk2, data_msk3);
                        cout<<endl;
                        cout<<"Data Sudah Ditambahkan"<<endl<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Sampai bertemu kembali"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 2 :
                        hapusData();
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 3 :
                        tampilDataPengembalian();
                        cout<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    case 4 :
                        cout<<"Yakin ingin ke menu utama (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            goto menu;
                        }else{
                            system("cls");
                        }
                        break;
                    case 5 :
                        cout<<"Yakin anda ingin keluar dari menu (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    default:
                        cout<<"Pilihan tidak tersedia"<<endl;
                        cout<<"Keluar (y/t) ? ";
                        cin>>ya_tidak;
                        if (ya_tidak == 'y' || ya_tidak == 'Y'){
                            cout<<"Terima kasih"<<endl;
                            keluar = true;
                        }else{
                            system("cls");
                        }
                        break;
                    }
                }while (keluar == false);
                break;

            case 5 :
                cout<<"Yakin ingin keluar (y/t) ? ";
                cin>>ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<"Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
                break;

            default :
                cout<<"Pilihan tidak tersedia"<<endl;
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<"Terima kasih"<<endl;
                    keluar = true;
                }else{
                    system("cls");
                }
                break;
            }
        }while (keluar == false);

     }else if (pilih == 2){
         cout<<"Masukkan Username       : ";
         cin>>userLogin;
         cout<<"Masukkan Password (NIM) : ";
         cin>>userPw;
         system("cls");
         menuUser :
         system("cls");
         cout<<"\t\t"<<"Menu User"<<endl;
         cout<<"1. Pencarian Buku"<<endl;
         cout<<"2. Keluar"<<endl;
         cout<<"silahkan pilih menu (1-2) : ";
         cin>>pilihan;
         system("cls");
         switch(pilihan){
         case 1 :
            cariBuku :
            system("cls");
            cout<<"\t\t"<<"Pencarian Buku"<<endl<<endl;
            cout<<"Silahkan masukkan kategori buku yang dicari : ";
            cin>>dataCari;
            tampilDataSearch();
            interpolationSearch(panjangArray);
            if(ketemu > 0){
                cout<<"Data ditemukan"<<endl;
                kategoriKebuku();
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<"Terima kasih"<<endl;
                    keluar = true;
                }else{
                    goto cariBuku;
                }
            }else{
                cout<<"Data tidak ditemukan"<<endl<<endl;
                cout<<"Keluar (y/t) ? ";
                cin>>ya_tidak;
                if (ya_tidak == 'y' || ya_tidak == 'Y'){
                    cout<<"Terima kasih"<<endl;
                    keluar = true;
                }else{
                    goto cariBuku;
                }
            }
            break;

         case 2 :
             cout<<"Yakin ingin keluar (y/t) ? ";
             cin>>ya_tidak;
             if (ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Terima kasih"<<endl;
                keluar = true;
             }else{
                goto menuUser;
             }
             break;

         default :
            cout<<"Pilihan tidak tersedia"<<endl;
            cout<<"Keluar (y/t) ? ";
            cin>>ya_tidak;
            if (ya_tidak == 'y' || ya_tidak == 'Y'){
                cout<<"Terima kasih"<<endl;
                keluar = true;
            }else{
                goto menuUser;
            }
            break;
         }

    }else if(pilih = 3){
        cout<<"Yakin ingin keluar (y/t) ? ";
        cin>>ya_tidak;
        if (ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<"Terima kasih"<<endl;
            keluar = true;
        }else{
            goto login;
        }

    }else{
        cout<<"Pilihan tidak tersedia"<<endl;
        cout<<"Keluar (y/t) ? ";
        cin>>ya_tidak;
        if (ya_tidak == 'y' || ya_tidak == 'Y'){
            cout<<"Terima kasih"<<endl;
            keluar = true;
        }else{
            goto login;
        }
    }

    return 0;
}
