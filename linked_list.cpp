#include <iostream>
#include <malloc.h>
#include <cctype>
using namespace std;

struct linked_list
{
    char isi;
    int posisi;
    linked_list *next;
    linked_list *prev;
};

linked_list *head, *tail, *cur, *del, *newnode, *afternode;

void sisipnode(char data)
{   
    int n;
    cout << "Masukkan jumlah node yang ingin disisipkan: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data: ";
        cin >> data;
        data = toupper(data); 
        newnode = new linked_list();
        newnode->isi = data;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void sisipdepan(char data)
{
   int n;
    cout << "Masukkan jumlah node yang ingin disisipkan: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
         cout << "Masukkan data: "; cin >> data;
         data = toupper(data); 
         newnode = new linked_list();
         newnode->isi = data;
         newnode->next = head;
         newnode->prev = nullptr;

         if (head != nullptr)
         {
             head->prev = newnode;
         }
         head = newnode;

         if (tail == nullptr)
         {
             tail = newnode;
         }
    }
   
}

void sisiptengah(char data, int posisi){
    int n;
    cout << "Masukkan jumlah node yang ingin disisipkan: "; cin >> n;
    cout << "Masukkan posisi yang ingin disisipkan: "; cin >> posisi;
    for (int i = 0; i < n; i++)
    {
        if (posisi == 1){
            cout << "posisi 1 bukan posisi tengah";
        } else if (posisi < 1) {
            cout << "posisi diluar jangkauan";
        } else {
        cout << "Masukkan data: "; cin >> data;
         data = toupper(data); 
        newnode = new linked_list();
        newnode->isi = data;
        cur = head;
        int nomor = 1;
        while (nomor < posisi-1)
        {
            cur = cur->next;
            nomor++;
        }
        afternode = cur->next;
        cur->next = newnode;
        afternode->prev = newnode;
        newnode->prev = cur;
        newnode->next = afternode;
        
    }
    }
}

void sisipbelakang(char data)
{
    int n;
    cout << "Masukkan jumlah node yang ingin disisipkan: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data: "; cin >> data;
        newnode = new linked_list();
        newnode->isi = data;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void hapusdepan()
{
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else if (head->next == NULL)
    {
        del = head;
        head = NULL;
        tail = NULL;
        delete del;
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void hapustengah(int posisi)
{
    cout << "Masukkan posisi yang ingin dihapus: "; cin >> posisi;
    if(head == NULL){
        cout << "list kosong";
    } else if(posisi == 1){
        cout << "posisi 1 bukan posisi tengah";
    } else if(posisi < 1){
        cout << "posisi diluar jangkauan";
    } else {    
        cur = head;
        int nomor = 1;
        while (nomor < posisi-1)
        {
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        afternode = del->next;
        cur->next = afternode;
        afternode->prev = cur;
        delete del;
    }
}

void hapusbelakang(){
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    } else {
        del = tail;
        tail = tail->prev;
        tail->next = head;
        head -> prev = tail;
        delete del;
    }

}

void bacamaju()
{
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        cout << "Isi List: ";
        cur = head;
        while (cur->next != head)
        {
            cout << cur->isi << " ";
            cur = cur->next;
        }
        cout << cur->isi;
        cout << endl;
    }
}

void bacamundur(){
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        cout << "Isi List: ";
        cur = tail;
        while (cur->prev != tail)
        {
            cout << cur->isi << " ";
            cur = cur->prev;
        }
        cout << cur->isi;
        cout << endl;
    }
}

int main()
{
    int pilih;
    char ulang;
    linked_list double_ll;
    int menu;
    do
    {
        system("cls");
        cout << "Pilih Program yang akan dijalankan: " << endl;
        cout << "1. Sisip Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Baca Maju" << endl;
        cout << "4. Baca Mundur" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
        do{
            system("cls");
            cout << "Menu Sisip Node" << endl;
            cout << "Pilih Menu " << endl; 
            cout << "1. Buat Node Baru" << endl;
            cout << "2. Sisip Depan" << endl;
            cout << "3. Sisip Tengah" << endl;
            cout << "4. Sisip Belakang" << endl;
            cout << "5. Kembali" << endl;
            cout << "Pilihan: "; cin >> menu;
            switch(menu){
                case 1:
                sisipnode(double_ll.isi);
                break;
                case 2:
                sisipdepan(double_ll.isi);
                break;
                case 3:
                sisiptengah(double_ll.isi, double_ll.posisi);
                break;
                case 4:
                sisipbelakang(double_ll.isi);
                break;
                case 5:
                break;
            }
        }while(menu != 5);
            break;
        case 2:
            cout << "Hapus Node" << endl;
            do{
                system("cls");
                cout << "Menu Hapus Node" << endl;
                cout << "Pilih Menu " << endl;
                cout << "1. Hapus Depan" << endl;
                cout << "2. Hapus Tengah" << endl;
                cout << "3. Hapus Belakang" << endl;
                cout << "4. Kembali" << endl;
                cout << "Pilihan: "; cin >> menu;
                switch(menu){
                    case 1:
                    hapusdepan();
                    break;
                    case 2:
                    hapustengah(double_ll.posisi);
                    break;
                    case 3:
                    hapusbelakang();
                    break;
                    case 4:
                    break;
                }
            }while (menu != 4);
            break;
        case 3:
            cout << "Baca Maju" << endl;
            bacamaju();
            break;
        case 4:
            cout << "Baca Mundur" << endl;
            bacamundur();
            break;
        case 5:
            exit(0);
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
        cout << "Apakah anda ingin mengulang program? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
