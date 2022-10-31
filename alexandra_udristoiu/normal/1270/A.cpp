#include<iostream>
using namespace std;
int n, nr1, nr2, i, t, ok, x;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> nr1 >> nr2;
        ok = 0;
        for(i = 1; i <= nr1; i++){
            cin>> x;
            if(x == n){
                ok = 1;
            }
        }
        for(i = 1; i <= nr2; i++){
            cin>> x;
        }
        if(ok == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}