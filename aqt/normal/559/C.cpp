#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long MOD = 1e9+7;
long long fact[200005];
long long dp[2005];
pair<int, int> cord[2005];

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
    long long ret = qikpow(b, e>>1);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

long long choose(long long n, long long r){
    return divd(fact[n], mult(fact[n-r], fact[r]));
}

int main(){
    cin >> N >> M >> K;
    for(int k = 1; k<=K; k++){
        cin >> cord[k].first >> cord[k].second;
    }
    cord[K+1].first = N, cord[K+1].second = M;
    sort(cord+1, cord+1+K);
    fact[0] = 1;
    for(int i = 1; i<=N+M; i++){
        fact[i] = mult(fact[i-1], i);
    }
    for(int k = 1; k<=K+1; k++){
        dp[k] = choose(cord[k].first-1+cord[k].second-1, cord[k].first-1);
        for(int i = 1; i<k; i++){
            if(cord[i].second <= cord[k].second){
                dp[k] = sub(dp[k], mult(dp[i],
                    choose(cord[k].first-cord[i].first+cord[k].second-cord[i].second, cord[k].first-cord[i].first)));
            }
        }
    }
    cout << dp[K+1] << endl;
}