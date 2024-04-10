#include<iostream>
using namespace std;
int n, m, b, mod, i, j, ii, t, sol;
int d[2][505][505], a[505];
int modul(int x){
    if(x >= mod){
        return x - mod;
    }
    return x;
}
int main(){
    cin>> n >> m >> b >> mod;
    d[0][0][0] = 1;
    for(i = 1; i <= n; i++){
        cin>> a[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j <= m; j++){
            for(ii = 0; ii <= b; ii++){
                d[1 - t][j][ii] = modul(d[1 - t][j][ii] + d[t][j][ii]);
                if(ii + a[i] <= b){
                    d[t][j + 1][ii + a[i] ] = modul(d[t][j + 1][ii + a[i] ] + d[t][j][ii]);
                }
                if(i != n){
                    d[t][j][ii] = 0;
                }
            }
        }
        t = 1 - t;
    }
    for(j = 0; j <= b; j++){
        sol = modul(sol + d[1 - t][m][j]);
    }
    cout<< sol;
}