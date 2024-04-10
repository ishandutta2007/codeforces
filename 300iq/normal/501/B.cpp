#include <iostream>
#include<string.h>
using namespace std;
int q;
string oldb;
string newb;
bool logic(string* arr, int q, string s){
for(int i = 0; i < q; i++){
    if(arr[i] == s){
        return true;
    }
}
return false;

}
int lolic(string* arr, int q, string s){
for(int i = 0; i < q; i++){
    if(arr[i] == s){
        return i;
    }
}
return -1;

}
int n = 0;
int main()
{
    cin >> q;
    string arr[q];
    string buff;
    string t[q];
    string f[q];
    int j = 0;
    string answers[q];
    for(int i = 0; i < q; i++){
        cin>>oldb;
        cin>>newb;
        arr[i]= newb;

        if(logic(arr, q, oldb)==true){
            t[lolic(t, q, oldb)] = newb;
        }
        else{

            f[n] = oldb;
            t[n] = newb;
            n+=1;


        }

        oldb = newb;
    }
    cout<<n<<endl;
    for(int i = 0; i<n; i++){
        cout<<f[i]<<' '<<t[i]<<endl;
    }

}