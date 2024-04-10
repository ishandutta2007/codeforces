#include<iostream>
#define mod 998244353
using namespace std;
int n, m, i, k, j, ii, pt, t, nr;
long long v[40], p[40], s[40], x;
int d[2][38][( 1 << 13) + 2], num[(1 << 18) + 5], w[40];
int calc(long long x){
    return num[ (x >> 18) ] + num[ (x & 262143) ];
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> x;
        for(ii = m - 1; ii >= 0; ii--){
            if( ( (x >> ii) & 1) == 1){
                if(p[ii] != 0){
                    x ^= p[ii];
                }
                else{
                    p[ii] = x;
                    v[++k] = x;
                    break;
                }
            }
        }
    }
    for(i = 1; i < (1 << 18); i++){
        num[i] = num[i / 2] + i % 2;
    }
    if(k <= 22){
        while(w[0] == 0){
            x = 0;
            for(i = 1; i <= k; i++){
                if(w[i] == 1){
                    x ^= v[i];
                }
            }
            s[ calc(x) ]++;
            i = k;
            while(w[i] == 1){
                w[i] = 0;
                i--;
            }
            w[i] = 1;
        }
    }
    else{
        for(i = m - 2; i >= 0; i--){
            for(j = i + 1; j < m; j++){
                if(p[i] != 0 && p[j] != 0){
                    if( ( (p[j] >> i) & 1) == 1){
                        p[j] ^= p[i];
                    }
                }
            }
        }
        k = 0;
        for(i = 0; i < m; i++){
            if(p[i] != 0){
                v[++k] = p[i];
            }
        }
        d[0][0][0] = 1;
        t = 1;
        for(i = 1; i <= k; i++){
            x = nr = 0;
            for(ii = 0; ii < m; ii++){
                if(p[ii] == 0){
                    if( ( (v[i] >> ii) & 1) == 1){
                        x += (1LL << nr);
                    }
                    nr++;
                }
            }
            for(j = 0; j < i; j++){
                for(ii = 0; ii < (1 << nr); ii++){
                    d[t][j][ii] = (d[t][j][ii] + d[1 - t][j][ii]) % mod;
                    d[t][j + 1][ (ii ^ x) ] = (d[t][j + 1][ (ii ^ x) ] + d[1 - t][j][ii]) % mod;
                    d[1 - t][j][ii] = 0;
                }
            }
            t = 1 - t;
        }
        t = 1 - t;
        for(j = 0; j <= k; j++){
            for(ii = 0; ii < (1 << nr); ii++){
                s[j + calc(ii) ] = (s[j + calc(ii) ] + d[t][j][ii]) % mod;
            }
        }
    }
    pt = 1;
    for(i = 1; i <= n - k; i++){
        pt = pt * 2 % mod;
    }
    for(i = 0; i <= m; i++){
        cout<< s[i] * 1LL * pt % mod <<" ";
    }
}