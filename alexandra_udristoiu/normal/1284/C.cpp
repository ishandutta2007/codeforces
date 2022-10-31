#include<iostream>
using namespace std;
int n, i, mod, sol, x;
int p[250005];
int main(){
    cin>> n >> mod;
    p[0] = 1;
    for(i = 1; i <= n; i++){
        p[i] = p[i - 1] * 1LL * i % mod;
    }
    for(i = 1; i <= n; i++){
        x = (n - i + 1) * 1LL * (n - i + 1) % mod * p[i] % mod * p[n - i] % mod;
        sol = (sol + x) % mod;
    }
    cout<< sol;
}