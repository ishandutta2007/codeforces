#include<iostream>
#define mod 998244353
using namespace std;
int n, i, j, x, sol;
int ff[5005], d[5005][5005], s[5005][5005], im[5005];
void inv(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        inv(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
int invmod(int a){
    long long x, y;
    inv(a, mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return x;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        ff[x]++;
    }
    s[0][0] = d[0][0] = 1;
    for(i = 1; i <= n; i++){
        s[0][i] = 1;
    }
    for(i = 1; i <= n; i++){
        im[i] = invmod(i);
    }
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            if(ff[j] > 0){
                d[i][j] = s[i - 1][j - 1] * 1LL * ff[j] % mod * im[n - i + 1] % mod;
                if(ff[j] > 1){
                    sol = (sol + d[i][j] * 1LL * im[n - i] % mod * (ff[j] - 1) ) % mod;
                }
            }
            s[i][j] = (s[i][j - 1] + d[i][j]);
            if(s[i][j] >= mod){
                s[i][j] -= mod;
            }
        }
    }
    cout<< sol;
}