#include<iostream>
#include<cstdio>
#include<algorithm>
#define DIM 1000005
#define mod 1000000007
using namespace std;
int n, i, st, dr, mid, sol, m, num, x, y, z;
int fact[DIM], nr[DIM], v[DIM], s1[DIM], s2[DIM], w[DIM];
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
int invmod(int n){
    long long a = n, b = mod, x, y;
    ff(a, b, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return x;
}
int comb(int n, int k){
    return fact[n] * 1LL * invmod(fact[k] * 1LL * fact[n - k] % mod) % mod;
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        w[i] = v[i];
    }
    sort(w + 1, w + n + 1);
    m = 1;
    for(i = 2; i <= n; i++){
        if(w[m] != w[i]){
            w[++m] = w[i];
        }
    }
    for(i = 1; i <= n; i++){
        st = 1;
        dr = m;
        while(st <= dr){
            mid = (st + dr) / 2;
            if(w[mid] == v[i]){
                break;
            }
            else{
                if(w[mid] < v[i]){
                    st = mid + 1;
                }
                else{
                    dr = mid - 1;
                }
            }
        }
        v[i] = mid;
        nr[mid]++;
    }
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * 1LL * i % mod;
    }
    s1[0] = s2[m + 1] = 1;
    for(i = 1; i <= m; i++){
        s1[i] = s1[i - 1] * 1LL * fact[ nr[i] ] % mod;
    }
    for(i = m; i >= 1; i--){
        s2[i] = s2[i + 1] * 1LL * fact[ nr[i] ] % mod;
    }
    for(i = m; i >= 1; i--){
        if(i == m){
            num += nr[i];
            continue;
        }
        y = fact[num + nr[i] - 1];
        z = fact[n - num - nr[i] ];
        x = comb(n, num + nr[i]) * 1LL * y % mod * z % mod;
        sol = (sol + w[i] * 1LL * x % mod * nr[i]) % mod;
        num += nr[i];
    }
    cout<< sol;
}