#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 998244353;
long long dp[5005][5005];
int arr[5005], pre[5005];
long long p[5005];

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long add(long long a, long long b){
    long long s = a+b;
    if(s >= MOD){
        s -= MOD;
    }
    return s;
}

long long qikpow(long long b, long long e){
    if(p[b]){
        return p[b];
    }
    if(!e){
        return 1;
    }
    long long res = qikpow(b, e>>1);
    res = mult(res, res);
    if(e&1){
        res = mult(res, b);
    }
    return p[b] = res;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int i = 1; i<=N; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    dp[0][0] = 1;
    long long ans = 0;
    for(int k = 1; k<=N; k++){
        long long s = 0;
        for(int i = 1; i<=N; i++){
            s = add(dp[i-1][k-1], s);
            dp[i][k] = mult(s, divd(arr[i], N-(k-1)));
            ans = add(ans, mult(dp[i][k], divd(arr[i]-1, N-k)));
        }
    }
    cout << ans << "\n";
}