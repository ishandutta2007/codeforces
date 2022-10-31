#include<iostream>
#define DIM 200005
#define mod 998244353
using namespace std;
long long n, m, nr, i, sol, nrinv;
long long v[DIM], s1[DIM], s2[DIM], num[DIM], sum[DIM], ff[DIM], aib[DIM];
long long x, y;
void invmod(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        invmod(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
void update(long long x, int val){
    for(; x <= n; x += (x & -x)){
        aib[x]++;
    }
}
long long query(long long x){
    long long sum = 0;
    for(; x >= 1; x -= (x & -x)){
        sum += aib[x];
    }
    return sum;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        if(v[i] == -1){
            m++;
        }
        else{
            ff[ v[i] ] = 1;
        }
    }
    num[0] = num[1] = 1;
    for(i = 2; i <= n; i++){
        num[i] = num[i - 1] * 1LL * i % mod;
        sum[i] = (sum[i - 1] * 1LL * i + i * 1LL * (i - 1) / 2 % mod * num[i - 1]) % mod;
    }
    for(i = 1; i <= n; i++){
        if(v[i] == -1){
            nr++;
        }
        else{
            s1[ v[i] ] = nr;
            s2[ v[i] ] = m - nr;
        }
    }
    for(i = 2; i <= n; i++){
        s1[i] += s1[i - 1];
        if(s1[i] >= mod){
            s1[i] -= mod;
        }
    }
    for(i = n - 1; i >= 1; i--){
        s2[i] += s2[i + 1];
        if(s2[i] >= mod){
            s2[i] -= mod;
        }
    }
    for(i = 1; i <= n; i++){
        if(ff[i] == 0){
            sol += s1[i] + s2[i];
            sol %= mod;
        }
    }
    nrinv = (n - m) * 1LL * (n - m - 1) / 2 % mod;
    for(i = 1; i <= n; i++){
        if(v[i] != -1){
            nrinv -= query(v[i]);
            if(nrinv < 0){
                nrinv += mod;
            }
            update(v[i], 1);
        }
    }
    sol = (sol * 1LL * num[ max(m - 1, 0LL) ] + sum[m] + nrinv * 1LL * num[m]) % mod;
    invmod(num[m], mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    sol = sol * 1LL * x % mod;
    cout<< sol;
}