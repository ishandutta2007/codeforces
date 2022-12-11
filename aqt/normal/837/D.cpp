#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[205][6000];

int mul(long long n, long long f){
    int cnt = 0;
    while(n%f == 0){
        n/=f;
        cnt++;
    }
    return cnt;
}

int main(){
    cin >> N >> K;
    for(int j =0; j<=K; j++){
        for(int k = 0; k<6000; k++){
            dp[j][k] = -1;
        }
    }
    dp[0][0] = 0;
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        long long n;
        cin >> n;
        long long num2 = mul(n, 2), num5 = mul(n, 5);
        for(int j = min(i, K); j>=1; j--){
            for(long long k = 5999; k>=num5; k--){
                if(dp[j-1][k-num5] != -1){
                    dp[j][k] = max(dp[j-1][k-num5] + num2, dp[j][k]);
                    ans = max(ans, min(k, dp[j][k]));
                }
            }
        }
    }
    cout << ans << endl;
}