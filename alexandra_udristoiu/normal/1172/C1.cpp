#include<iostream>
#define mod 998244353
using namespace std;
int n, i, j, jj, k, s, s0, s1, sc, s0c, s1c, sum, m, val;
int d[52][52][52], v[52], a[52];
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
        cin>> v[i];
        s += v[i];
        if(a[i] == 0){
            s0 += v[i];
        }
        else{
            s1 += v[i];
        }
    }
    for(k = 1; k <= n; k++){
        d[0][0][0] = 1;
        for(i = 0; i < m; i++){
            for(j = 0; j <= i; j++){
                for(jj = 0; jj <= i; jj++){
                    sc = s + j - (i - j);
                    s0c = s0 - (i - j);
                    s1c = s1 + j;
                    val = v[k];
                    if(a[k] == 0){
                        val -= jj;
                        s0c -= val;
                    }
                    else{
                        val += jj;
                        s1c -= val;
                    }
                    d[i + 1][j + a[k] ][jj + 1] = (d[i + 1][j + a[k] ][jj + 1] + d[i][j][jj] * 1LL * val % mod * invmod(sc)) % mod;
                    d[i + 1][j + 1][jj] = (d[i + 1][j + 1][jj] + d[i][j][jj] * 1LL * s1c % mod * invmod(sc)) % mod;
                    d[i + 1][j][jj] = (d[i + 1][j][jj] + d[i][j][jj] * 1LL * s0c % mod * invmod(sc)) % mod;
                }
            }
        }
        sum = 0;
        for(j = 0; j <= m; j++){
            for(jj = 0; jj <= m; jj++){
                val = v[k];
                if(a[k] == 0){
                    val -= jj;
                }
                else{
                    val += jj;
                }
                sum = (sum + val * 1LL * d[m][j][jj]) % mod;
            }
        }
        for(i = 0; i <= m; i++){
            for(j = 0; j <= i; j++){
                for(jj = 0; jj <= i; jj++){
                    d[i][j][jj] = 0;
                }
            }
        }
        cout<< sum <<"\n";
    }
}