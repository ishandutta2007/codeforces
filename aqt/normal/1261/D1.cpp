#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
int arr[200005];
long long MOD = 998244353;
long long pows[2][200005];
long long fact[200005];

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

long long combo(long long n, long long r){
    return divd(fact[n], mult(fact[r], fact[n-r]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    if(K==1){
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i = 0; i<N; i++){
        if(arr[i] == arr[(i+1)%N]){
            cnt++;
        }
    }
    pows[0][0] = pows[1][0] = fact[0] = 1;
    for(int i = 1; i<=N; i++){
        pows[0][i] = mult(2, pows[0][i-1]);
        pows[1][i] = mult(K, pows[1][i-1]);
        fact[i] = mult(fact[i-1], i);
    }
    long long ans = 0;
    for(int i = 1; i<=N-cnt; i++){
        long long c = mult(combo(N-cnt, i), qikpow(K-2, N-cnt-i)); //K = 2 alert
        long long t = divd(pows[0][i], 2);
        if(i%2 == 0){
            t = add(t, -divd(combo(i, i/2), 2));
            if(t < 0){
                t += MOD;
            }
        }
        ans = add(ans, mult(c, t));
    }
    cout << mult(ans, pows[1][cnt]) << "\n";
}