#include<iostream>
#define DIM 200005
#define mod 998244353
using namespace std;
int n, m, i, j, s, s0, s1, sc, s0c, s1c;
int w[DIM], d[3005][3005], e[3005][3005], a[DIM], inv[6005];
void ff(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        ff(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
int invmod(int a){
    long long x, y;
    ff(a, mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return (int) x;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> a[i];
    }
    for(i = 1; i <= n; i++){
        cin>> w[i];
        s += w[i];
        if(a[i] == 1){
            s1 += w[i];
        }
        else{
            s0 += w[i];
        }
    }
    for(i = 0; i <= m; i++){
        d[m][i] = e[m][i] = 1;
    }
    for(i = -m; i <= m; i++){
        if(s + i > 0){
            inv[i + m] = invmod(s + i);
        }
    }
    for(i = m - 1; i >= 0; i--){
        for(j = 0; j <= i; j++){
            sc = s + j - (i - j);
            s1c = s1 + j;
            s0c = s0 - (i - j);
            if(s0c < 0){
                continue;
            }
            d[i][j] = ( (s1c + 1) * 1LL * d[i + 1][j + 1] % mod + s0c * 1LL * d[i + 1][j] % mod) * inv[j - (i - j) + m] % mod;
            e[i][j] = (s1c * 1LL * e[i + 1][j + 1] % mod + (s0c - 1) * 1LL * e[i + 1][j] % mod) * inv[j - (i - j) + m] % mod;
        }
    }
    for(i = 1; i <= n; i++){
        if(a[i] == 1){
            cout<< d[0][0] * 1LL * w[i] % mod <<"\n";
        }
        else{
            cout<< e[0][0] * 1LL * w[i] % mod <<"\n";
        }
    }
}