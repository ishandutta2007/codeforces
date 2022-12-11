#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 998244353;
long long fact[1000005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long sub(long long a, long long b){
    return ((a-b)%MOD+MOD)%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

int main(){
    cin >> N;
    fact[0] = 1;
    for(int i = 1; i<=N; i++){
        fact[i] = mult(fact[i-1], i);
    }
    long long ans = fact[N];
    for(int i = 1; i<N; i++){
        ans = add(ans, mult(divd(fact[N], fact[i]), sub(fact[i], 1)));
    }
    cout << ans << endl;
}