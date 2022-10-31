#include<iostream>
#define mod 998244353
using namespace std;
int n, i, val, sum;
int main(){
    cin>> n;
    val = 1;
    for(i = n; i >= 2; i--){
        val = val * 1LL * i % mod;
        sum = (sum + val) % mod;
    }
    val = (val * 1LL * n % mod - sum + mod) % mod;
    cout<< val;
}