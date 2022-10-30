#include<iostream>
using namespace std;
int q, x, y;
int nr1, nr2, b1[100], b2[100];
int main(){
    cin>> q;
    for(; q; q--){
        cin>> x >> y;
        if(x > y){
            cout<<"NO\n";
            continue;
        }
        nr1 = nr2 = 0;
        for(int i = 1; i < (1 << 30); i *= 2){
            if( (x & i) == i){
                b1[++nr1] = i;
            }
        }
        for(int i = 1; i < (1 << 30); i *= 2){
            if( (y & i) == i){
                b2[++nr2] = i;
            }
        }
        int ok = 1;
        if(nr2 > nr1){
            ok = 0;
        }
        for(int i = 1; i <= nr2; i++){
            if(b2[i] < b1[i]){
                ok = 0;
            }
        }
        if(ok == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}