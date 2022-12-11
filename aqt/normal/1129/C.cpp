#include <bits/stdc++.h>

using namespace std;

int N;
int arr[3005];
int nxt[2][5000000];
int cnt = 0;
long long dp[3005][3005];
long long MOD = 1e9+7;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i =1 ; i<=N; i++){
        dp[i][i-1] = 1;
        for(int j = i; j<=N; j++){
            dp[i][j] = (dp[i][j-1] + dp[i][j-2] + dp[i][j-3])%MOD;
            if(j-i+1 >= 4){
                int v = (arr[j-3]<<3)+(arr[j-2]<<2)+(arr[j-1]<<1)+arr[j];
                if(v != 3 && v != 5 && v != 14 && v != 15){
                    dp[i][j] += dp[i][j-4];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for(int i =1 ; i<=N; i++){
        int crnt = 0;
        for(int j = i; j>0; j--){
            if(nxt[arr[j]][crnt]){
                crnt = nxt[arr[j]][crnt];
            }
            else{
                nxt[arr[j]][crnt] = ++cnt;
                crnt = cnt;
                ans += dp[j][i];
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}