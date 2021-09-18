#include <iostream>

using namespace std;
// Initialize a hash table with static length
const int hash_table_size = 1e3+9;
string arr[hash_table_size];
int table_size = 1e5+3;


// This function calculates the hash value of the given key with type string
int hash_function_str_complex(string key) {
    int res = 0;
    for (int i = 0 ; i < key.size() ; i++)
        res = (res + 37LL * key[i]) % hash_table_size;
    return res;
}

// This function searches for an element in the hash table
bool search_item(string key) {
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // loop till find the given key
    int i = 0;
    while (arr[(idx + i) % hash_table_size] != key &&
		   arr[(idx + i) % hash_table_size] != "")
        i++;
    // return whether the current position in the hash table contain the given key
    return arr[(idx + i) % hash_table_size] == key;
}

// This function inserts an element in the hash table
void insert_item(string key) {
	// check if the given key exists or not
    if (search_item(key) == true)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // loop till find an empty position
    int i = 0;
    while (arr[(idx + i) % hash_table_size] != "" &&
		   arr[(idx + i) % hash_table_size] != "#")
        i++;
    // insert the new element
    arr[(idx + i) % hash_table_size] = key;
}

// This function deletes an element at the given index in the hash table
void delete_item(string key) {
	// check if the given key exists or not
    if (search_item(key) == false)
        return;
    // calculate the hash value of the given key
    int idx = hash_function_str_complex(key);
    // loop till find the given key
    int i = 0;
    while (arr[(idx + i) % hash_table_size] != key)
        i++;
    // set the position of the deleted element as a hash sign
    arr[(idx + i) % hash_table_size] = "#";
}

// This function prints the contents of the hash table
void print_hash_table() {
    int j=1;
    // loop to print the elements in the hash table
    for (int i = 0 ; i < hash_table_size ; i++) {
        if (arr[i] == "" || arr[i] == "#")
            continue;
        cout <<"contaract number "<<j++<<" "<< arr[i] << '\n';
    }
}

int hash_function_str(string x) {
    int res = 0;
    for (int i = 0 ; i < x.size() ; i++)
        res = (res + x[i]) % table_size;
    return res;
}
//----------------------------------------------------------------------------------------------------------------------------//

void search_word(){
cout<<"please enter the word you wanted to search about it : ";
string word;
cin>>word;
if(search_item(word)){
    cout<<"this word is founded"<<endl;
}
else{
        cout<<"this word is NOT found"<<endl;

}
}
void delete_word(){
cout<<"please enter the word you wanted to delete it from your contract phone : ";
string word;
cin>>word;
delete_item(word);

}
void insert_node(){
cout<<"please enter the word you wanted to add it to your contract : ";
string word;
cin>>word;
insert_item(word);

}




int main() {

	insert_item("aaa");
		insert_item("bbb");
			insert_item("ccc");
				insert_item("ddd");





	while(1){
            cout<<"\n====PHONE CONTRACT===="<<endl;

    cout<<"\nPlease choose what you want to do";

    cout<<"\n1.Search for contract";
    cout<<"\n2.Delete contract ";
    cout<<"\n3.insert contract"; 
    cout<<"\n4.View my contract";  

    cout<<"\n5.exit";


        cout<<"\n\nEnter your choice..";

        int choice;
        cin>>choice;
        switch(choice){
      case 1:
          search_word();
        break;
      case 2:
          delete_word();
        break;
      case 3:
          insert_node();
        break;
      case 4:
         print_hash_table();
         break;
      case 5:
        exit(0);

    }
}
}
