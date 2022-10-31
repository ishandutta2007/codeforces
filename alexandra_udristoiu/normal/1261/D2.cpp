#include<iostream>
#define mod 998244353
#define DIM 200005
using namespace std;
int n, k, i, sol, x, inv, nr;
int fact[DIM], v[DIM];
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 1){
            return a * 1LL * a % mod * x % mod;
        }
        else{
            return a * 1LL * a % mod;
        }
    }
}
int comb(int n, int k){
    int x = fact[k] * 1LL * fact[n - k] % mod;
    return mult(x, mod - 2) * 1LL * fact[n] % mod;
}
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    if(k == 1){
        cout<< 0;
        return 0;
    }
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * 1LL * i % mod;
        if(v[i] == v[i % n + 1]){
            nr++;
        }
    }
    inv = mult(2, mod - 2);
    for(i = 1; i <= n - nr; i++){
        if(i % 2 == 1){
            x = mult(2, i - 1);
        }
        else{
            x = mult(2, i) - comb(i, i / 2);
            if(x < 0){
                x += mod;
            }
            x = x * 1LL * inv % mod;
        }
        if(k != 2){
            sol = (sol + x * 1LL * mult(k - 2, n - nr - i) % mod * comb(n - nr, i) ) % mod;
        }
    }
    if(k == 2){
        sol = x;
    }
    for(i = 1; i <= nr; i++){
        sol = sol * 1LL * k % mod;
    }
    cout<< sol;
}