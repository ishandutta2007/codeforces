#include<iostream>
#define mod 998244353
using namespace std;
int n, m, k, i, j, ii, jj, ii2, jj2, sol;
int d[2][3605][3605][2], c[3605][3605], nr[2], v[2][3605], ff[2][3605], e[2][3605], fact[3605];
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= k; i++){
        cin>> ii >> jj >> ii2 >> jj2;
        ff[0][ii] = ff[0][ii2] = 1;
        ff[1][jj] = ff[1][jj2] = 1;
    }
    for(i = 1; i <= n; i++){
        if(ff[0][i] == 0){
            v[0][ ++nr[0] ] = i;
        }
    }
    for(i = 1; i <= m; i++){
        if(ff[1][i] == 0){
            v[1][ ++nr[1] ] = i;
        }
    }
    for(ii = 0; ii < 2; ii++){
        if(nr[ii] == 0){
            e[ii][0] = 1;
            continue;
        }
        d[ii][1][0][0] = 1;
        for(i = 2; i <= nr[ii]; i++){
            for(j = 0; j <= i / 2; j++){
                d[ii][i][j][0] = (d[ii][i - 1][j][0] + d[ii][i - 1][j][1]) % mod;
                if(j != 0 && v[ii][i - 1] == v[ii][i] - 1){
                    d[ii][i][j][1] = d[ii][i - 1][j - 1][0];
                }
            }
        }
        for(j = 0; j <= nr[ii] / 2; j++){
            e[ii][j] = (d[ii][ nr[ii] ][j][0] + d[ii][ nr[ii] ][j][1]) % mod;
        }
    }
    c[0][0] = 1;
    fact[0] = 1;
    for(i = 1; i <= max(n, m); i++){
        c[i][0] = 1;
        fact[i] = fact[i - 1] * 1LL * i % mod;
        for(j = 1; j <= i; j++){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    for(i = 1; i <= max(n, m); i++){
        for(j = 1; j <= i; j++){
            c[i][j] = c[i][j] * 1LL * fact[j] % mod;
        }
    }
    for(ii = 0; ii <= nr[0] / 2; ii++){
        for(jj = 0; jj <= nr[1] / 2; jj++){
            sol = (sol + e[0][ii] * 1LL * e[1][jj] % mod * c[ nr[0] - 2 * ii ][jj] % mod * c[ nr[1] - 2 * jj ][ii]) % mod;
        }
    }
    cout<< sol;
}