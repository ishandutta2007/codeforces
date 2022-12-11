#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long dp[55];
int ans[55];

int main(){
    cin >> N >> K;
    dp[0] = 1;
    for(int i = 1; i<=N; i++){
        dp[i] = dp[i-1];
        if(i-1){
            dp[i] += dp[i-2];
        }
    }
    long long crnt = 0;
    for(int idx = 0; idx<N; ){
        long long tot = 0;
        for(int j = 1; j <= 2; j++){
            if(dp[N-idx-j] + crnt + tot < K){
                tot += dp[N-idx-j];
            }
            else{
                int t = idx+j;
                crnt += tot;
                idx++;
                ans[idx] = idx+j-1;
                while(idx < t){
                    idx++;
                    ans[idx] = idx-1;
                }
                break;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}