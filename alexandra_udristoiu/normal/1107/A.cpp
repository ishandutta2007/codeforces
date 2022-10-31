#include<iostream>
using namespace std;
int t, n, i;
char v[304];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> v + 1;
        if(n == 2 && v[1] >= v[2]){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n2\n";
        cout<< v[1] <<" ";
        cout<< v + 2 <<"\n";
    }
}