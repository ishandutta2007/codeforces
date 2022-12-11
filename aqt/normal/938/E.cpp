#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[1000005];
long long fact[1000005];
long long MOD = 1e9+7;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long mid = qikpow(b, e/2);
    mid = mult(mid, mid);
    if(e&1){
        mid = mult(mid, b);
    }
    return mid;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

long long combo(long long n, long long r){
    //cout << fact[n] << " " << fact[r] << " " << fact[n-r] << endl;
    return divd(fact[n], mult(fact[r], fact[n-r]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fact[0] = 1;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        fact[i] = mult(fact[i-1], i);
    }
    sort(arr+1, arr+1+N);
    bool s = 1;
    long long ans = 0;
    int tot = 0;
    for(int i = N; i>0; i--){
        int cnt = 1;
        tot++;
        while(arr[i] == arr[i-1]){
            i--;
            cnt++;
            tot++;
        }
        if(s){
            s = 0;
            continue;
        }
//        cout << " " << mult(mult(arr[i], combo(N, tot)), mult(mult(cnt, fact[tot-1]), fact[N-tot])) << endl;
        ans = add(ans, mult(mult(arr[i], combo(N, tot)), mult(mult(cnt, fact[tot-1]), fact[N-tot])));
    }
    cout << ans << endl;
}