#include<iostream>
using namespace std;
int n, t, i, ok;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        ok = 0;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            if(i != 1 && v[i] != v[i - 1]){
                ok = 1;
            }
        }
        if(ok == 1){
            cout<<"1\n";
        }
        else{
            cout<< n <<"\n";
        }
    }
}