#include<iostream>
using namespace std;
int n, i, j, dr, sol, t, u, v, ok;
int a[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> u >> v;
        for(i = 1; i <= n; i++){
            cin>> a[i];
        }
        ok = 0;
        for(i = 2; i <= n; i++){
            if(a[i] - a[i - 1] >= 2 || a[i] - a[i - 1] <= -2){
                ok = 1;
            }
        }
        if(ok == 1){
            cout<<"0\n";
            continue;
        }
        ok = 0;
        for(i = 2; i <= n; i++){
            if(a[i] != a[i - 1]){
                ok = 1;
            }
        }
        if(ok == 0){
            sol = min(u + v, 2 * v);
        }
        else{
            sol = min(u, v);
        }
        cout<< sol <<"\n";
    }
}