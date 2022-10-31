#include<iostream>
#define mod 998244353
using namespace std;
int n, i, sol;
int v[200005];
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
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        v[i] = 100LL * mult(v[i], mod - 2) % mod;
    }
    for(i = 1; i <= n; i++){
        sol = (sol + 1) * 1LL * v[i] % mod;
    }
    cout<< sol;
}