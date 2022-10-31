#include<iostream>
#include<cstring>
#define DIM 100005
#define mod 1000000007
using namespace std;
int n, m, i, ii, jj, q, sol;
int d[55][DIM], fact[DIM], ff[55], a[55][55];
char s[DIM];
void f(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        f(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
int invmod(int a){
    long long x, y;
    f(a, mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return (int) x;
}
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    m = 52;
    for(i = 1; i <= n; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ff[ s[i] - 'a' + 1 ]++;
        }
        else{
            ff[ s[i] - 'A' + 27 ]++;
        }
    }
    fact[0] = 1;
    for(i = 1; i <= n / 2; i++){
        fact[i] = fact[i - 1] * 1LL * i % mod;
    }
    sol = fact[n / 2] * 1LL * fact[n / 2] % mod;
    for(i = 1; i <= m; i++){
        if(ff[i] > n / 2){
            sol = 0;
            break;
        }
        sol = sol * 1LL * invmod(fact[ ff[i] ]) % mod;
    }
    d[0][0] = 1;
    for(ii = 1; ii <= m; ii++){
        for(i = 0; i <= n / 2; i++){
            d[ii][i] = d[ii - 1][i];
            if(i >= ff[ii] && ff[ii] != 0){
                d[ii][i] += d[ii - 1][i - ff[ii] ];
                if(d[ii][i] >= mod){
                    d[ii][i] -= mod;
                }
            }
        }
    }
    for(ii = 1; ii <= m; ii++){
        for(jj = ii; jj <= m; jj++){
            if(ff[ii] + ff[jj] > n / 2 && ii != jj){
                continue;
            }
            for(i = 0; i <= n / 2; i++){
                d[m + 1][i] = d[m][i];
                if(i >= ff[ii] && ff[ii] != 0){
                    d[m + 1][i] -= d[m + 1][i - ff[ii] ];
                    if(d[m + 1][i] < 0){
                        d[m + 1][i] += mod;
                    }
                }
            }
            for(i = 0; i <= n / 2; i++){
                d[m + 2][i] = d[m + 1][i];
                if(i >= ff[jj] && ff[jj] != 0 && ii != jj){
                    d[m + 2][i] -= d[m + 2][i - ff[jj] ];
                    if(d[m + 2][i] < 0){
                        d[m + 2][i] += mod;
                    }
                }
            }
            a[ii][jj] = a[jj][ii] = d[m + 2][n / 2];
        }
    }
    cin>> q;
    for(; q; q--){
        cin>> ii >> jj;
        if(s[ii] >= 'a' && s[ii] <= 'z'){
            ii = s[ii] - 'a' + 1;
        }
        else{
            ii = s[ii] - 'A' + 27;
        }
        if(s[jj] >= 'a' && s[jj] <= 'z'){
            jj = s[jj] - 'a' + 1;
        }
        else{
            jj = s[jj] - 'A' + 27;
        }
        cout<< sol * 2LL * a[ii][jj] % mod <<"\n";
    }
    return 0;
}