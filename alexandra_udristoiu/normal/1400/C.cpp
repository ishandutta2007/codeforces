#include<iostream>
#include<cstring>
#define DIM 100005
using namespace std;
int t, n, i, x, ok;
char s[DIM], sol[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        cin>> x;
        for(i = 1; i <= n; i++){
            sol[i] = '1';
        }
        for(i = 1; i <= n; i++){
            if(s[i] == '0'){
                if(i - x >= 1){
                    sol[i - x] = '0';
                }
                if(i + x <= n){
                    sol[i + x] = '0';
                }
            }
        }
        ok = 1;
        for(i = 1; i <= n; i++){
            if(s[i] == '1'){
                if(i - x >= 1 && sol[i - x] == '1'){
                    continue;
                }
                if(i + x <= n && sol[i + x] == '1'){
                    continue;
                }
                ok = 0;
            }
        }
        if(ok == 0){
            cout<<"-1\n";
            continue;
        }
        sol[n + 1] = 0;
        cout<< sol + 1 <<"\n";
    }
}