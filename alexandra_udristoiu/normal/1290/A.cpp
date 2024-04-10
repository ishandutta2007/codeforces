#include<iostream>
using namespace std;
int t, n, k, m, i, j, sol, minim;
int v[3505];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m >> k;
        k = min(k, m - 1);
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        sol = 0;
        for(i = 0; i <= k; i++){
            minim = 1000000000;
            for(j = 0; j < m - k; j++){
                minim = min(minim, max(v[i + j + 1], v[n - m + i + j + 1]) );
            }
            sol = max(sol, minim);
        }
        cout<< sol <<"\n";
    }
}