#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long dp[10005];
vector<int> v[10005];
long long MOD = 1e9+7;
bool ans[10005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i =1 ; i<=Q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        v[l].push_back(x);
        v[r+1].push_back(-x);
    }
    dp[0] = 1;
    for(int i = 1; i<=N; i++){
        for(int n : v[i]){
            if(n > 0){
                for(int k = N; k>=n; k--){
                    dp[k] += dp[k-n];
                    if(dp[k] > MOD){
                        dp[k] -= MOD;
                    }
                }
            }
            else if(n < 0){
                for(int k = -n; k<=N; k++){
                    dp[k] -= dp[k+n];
                    if(dp[k] < 0){
                        dp[k] += MOD;
                    }
                }
            }
        }
        for(int k = 1; k<=N; k++){
            ans[k] |= dp[k];
        }
    }
    int cnt = 0;
    for(int i= 1; i<=N; i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i<=N; i++){
        if(ans[i]){
            cout << i << " ";
        }
    }
}