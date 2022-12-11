#include <bits/stdc++.h>

using namespace std;

long long A, B, N, X;
long long MOD = 1e9+7;

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long res = qikpow(b, e>>1);
    res = res*res%MOD;
    if(e&1){
        res = res*b%MOD;
    }
    return res;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    return add(add(a, -b), MOD);
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long divd(long long a, long long b){
    if(a == b){
        return 1;
    }
    return mult(a, qikpow(b, MOD-2));
}

int main(){
    cin >> A >> B >> N >> X;
    long long R = 0;
    if(A == 1){
        R = mult(B, N%MOD);
    }
    else{
        R = mult(B, divd(sub(qikpow(A, N),1), sub(A, 1)));
    }
    cout << add(mult(qikpow(A, N),X),R);
}