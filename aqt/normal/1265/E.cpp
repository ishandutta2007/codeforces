#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 998244353;
long long arr[200005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

long long mult(long long a, long long b){
    return a*b%MOD;
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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr[0] = 1;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        arr[i] = divd(arr[i], 100);
        arr[i] = mult(arr[i-1], arr[i]);
    }
    long long sum = 0;
    for(int i = 0; i<N; i++){
        sum = add(sum, arr[i]);
    }
    cout << divd(sum, arr[N]) << endl;
}