#include <bits/stdc++.h>

using namespace std;

long long N, K, MOD = 1e9+7;
vector<pair<long long, int>> v;
long long dp[55][10005];

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

long long div(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

long long solve(long long p, int n){
    for(int i = 0; i<=n; i++){
        for(int k = 0; k<=K; k++){
            dp[i][k] = 0;
        }
    }
    dp[n][0] = 1;
    for(int i = n; i>=0; i--){
        long long d = qikpow(i+1, MOD-2);
        for(int k = 0; k<K; k++){
            for(int j = 0; j<=i; j++){
                dp[j][k+1] = add(mult(d, dp[i][k]), dp[j][k+1]);
            }
        }
    }
    long long ret = 0;
    for(int i = 0; i<=n; i++){
        //cout << qikpow(p, i) << " " << dp[i][K] << endl;
        ret = add(ret, mult(qikpow(p, i), dp[i][K]));
    }
    //cout << p << " " << n << " " << ret << endl;
    return ret;
}

int main(){
    cin >> N >> K;
    for(long long n = 2; n<=sqrt(N); n++){
        int cnt = 0;
        while(N%n == 0){
            N /= n;
            cnt++;
        }
        if(cnt){
            v.push_back({n, cnt});
        }
    }
    if(N-1){
        v.push_back({N, 1});
    }
    long long ans = 1;
    for(auto p : v){
        ans = mult(ans, solve(p.first, p.second));
    }
    cout << ans << endl;
}