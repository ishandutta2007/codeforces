#include<iostream>
#define DIM 200005
#define mod 1000000007
using namespace std;
int n, i, sum1, sum2, nr;
int v[DIM];
long long x, y, fact[DIM];
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
long long comb(int n, int k){
    long long a = fact[k] * fact[n - k] % mod;
    invmod(a, mod, x, y);
    x %= mod;
    if(x < 0){
        x += mod;
    }
    return fact[n] * x % mod;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    if(n == 1){
        cout<< v[1];
        return 0;
    }
    fact[0] = 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i % mod;
    }
    while(nr % 2 == 1 || n % 2 == 1){
        for(i = 1; i < n; i++){
            if( (nr + i) % 2 == 1){
                v[i] += v[i + 1];
            }
            else{
                v[i] -= v[i + 1];
            }
            v[i] %= mod;
            if(v[i] < 0){
                v[i] += mod;
            }
        }
        nr += n - 1;
        n--;
    }
    for(i = 1; i <= n; i++){
        if(i % 2 == 1){
            sum1 = (sum1 + comb(n / 2 - 1, i / 2) * v[i]) % mod;
            if(sum1 < 0){
                sum1 += mod;
            }
        }
        else{
            sum2 = (sum2 + comb(n / 2 - 1, i / 2 - 1) * v[i]) % mod;
            if(sum2 < 0){
                sum2 += mod;
            }
        }
    }
    if( (n * 1LL * (n - 1) / 2) % 2 == 0){
        sum1 -= sum2;
        if(sum1 < 0){
            sum1 += mod;
        }
    }
    else{
        sum1 = (sum1 + sum2) % mod;
    }
    cout<< sum1;
    return 0;
}