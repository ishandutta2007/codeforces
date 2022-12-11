#include <bits/stdc++.h>

using namespace std;

long long dp[100005];
long long MOD = 1e9+7;

int main(){
    dp[0] = 2;
    dp[1] = 2;
    int N, M;
    cin >> N >> M;
    if(N < M){
        swap(N, M);
    }
    for(int i = 2; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    long long ans = dp[N]+dp[M]-2;
    ans %= MOD;
    if(ans < 0){
        ans += MOD;
    }
    cout << ans << endl;
}