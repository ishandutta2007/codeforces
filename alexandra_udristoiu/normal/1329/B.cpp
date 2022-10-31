#include<iostream>
using namespace std;
int n, mod, t, i, sol;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> mod;
        sol = 1;
        for(i = 0; (1 << i) <= n; i++){
            sol = sol * 1LL * ( min(n, (1 << (i + 1) ) - 1) - (1 << i) + 2) % mod;
        }
        sol = (sol - 1 + mod) % mod;
        cout<< sol <<"\n";
    }
}