#include<iostream>
#define mod 998244353
using namespace std;
int n, i, k, sol, val;
long long nr;
int fact[200005];
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
int comb(int n, int k){
    return fact[n] * 1LL * mult(fact[k] * 1LL * fact[n - k] % mod, mod - 2) % mod;
}
int main(){
    cin>> n >> nr;
    if(nr >= n){
        cout<< 0;
        return 0;
    }
    k = n - nr;
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * 1LL * i % mod;
    }
    if(k == n){
        cout<< fact[n];
    }
    else{
        for(i = k; i >= 1; i--){
            val = mult(i, n) * 1LL * comb(k, i) % mod;
            if(k % 2 == i % 2){
                sol = (sol + val) % mod;
            }
            else{
                sol = (sol - val + mod) % mod;
            }
        }
        sol = sol * 2LL * comb(n, k) % mod;
        cout<< sol;
    }
}