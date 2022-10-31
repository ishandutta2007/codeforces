#include<iostream>
#define mod 1000000007
using namespace std;
int n, m, a, b, i, sol, val;
int fact[1000005];
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
    return fact[n] * 1LL * mult(fact[k], mod - 2) % mod * mult(fact[n - k], mod - 2) % mod;
}
int main(){
    cin>> n >> m;
    fact[0] = 1;
    for(i = 1; i <= max(n, m); i++){
        fact[i] = fact[i - 1] * 1LL * i % mod;
    }
    for(i = 2; i <= min(m + 1, n); i++){
        if(i == n){
            val = fact[n - 2] * 1LL * comb(m - 1, n - 2) % mod;
        }
        else{
            val = i * 1LL * mult(n, n - i - 1) % mod * fact[n - 2] % mod * mult(fact[n - i], mod - 2) % mod * comb(m - 1, i - 2) % mod * mult(m, n - i) % mod;
        }
        sol = (sol + val) % mod;
    }
    cout<< sol;
}