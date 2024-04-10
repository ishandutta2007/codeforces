#include <bits/stdc++.h>

using namespace std;

int dp[2][1<<24];
int arr[25];
vector<pair<int, int>> sum[25];
int N;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            for(int k = 1; k<=N; k++){
                if(arr[i]+arr[j] == arr[k]){
                    sum[k].push_back({i-1, j-1});
                }
            }
        }
    }
    for(int i = 0; i<2; i++){
        for(int j = 0; j<1<<24; j++){
            dp[i][j] = 25;
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i<N; i++){
        for(int m = 1<<(i-1); m<1<<i; m++){
            dp[i&1][m] = max(dp[i&1][m], __builtin_popcount(m));
            for(pair<int, int> p : sum[i+1]){
                if(((1<<p.first)&m) && ((1<<p.second)&m)){
                    for(int k = 0; k<i; k++){
                        if((1<<k)&m){
                            dp[i&1^1][m^(1<<i)^(1<<k)] = min(dp[i&1^1][m^(1<<i)^(1<<k)], dp[i&1][m]);
                        }
                    }
                    dp[i&1^1][m^(1<<i)] = min(dp[i&1^1][m^(1<<i)], dp[i&1][m]);
                }
            }
        }
        for(int m = 1<<(i-1); m<1<<i; m++){
            dp[i&1][m] = 25;
        }
    }
    int ans = 25;
    for(int m = (1<<(N-1)); m<1<<N; m++){
        dp[N&1][m] = max(dp[N&1][m], __builtin_popcount(m));
        ans = min(ans, dp[N&1][m]);
    }
    if(ans == 25){
        ans = -1;
    }
    cout << ans << endl;
}