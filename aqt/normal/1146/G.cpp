#include <bits/stdc++.h>

using namespace std;

int N, H, Q;
int dp[55][55][55];
vector<pair<int, pair<int, int>>> a[55], b[55];

int solve(int l, int r, int h){
    if(l > r || !h){
        return 0;
    }
    if(dp[l][r][h] != -1){
        return dp[l][r][h];
    }
    dp[l][r][h] = solve(l, r, h-1);
    int tot = 0;
    for(int i = l; i<=r; i++){
        for(auto n : a[i]){
            if(n.first <= r && n.second.first < h){
                tot -= n.second.second;
            }
        }
        dp[l][r][h] = max(dp[l][r][h], h*h + tot + solve(l, i-1, h) + solve(i+1, r, h));
        for(auto n : b[i]){
            if(n.first >= l && n.second.first < h){
                tot += n.second.second;
            }
        }
    }
    return dp[l][r][h];
}

int main(){
    cin >> N >> H >> Q;
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            for(int h = 0; h<=H; h++){
                dp[i][j][h] = -1;
            }
        }
    }
    while(Q--){
        int l, r, lim, f;
        cin>> l >> r >> lim >> f;
        a[l].push_back({r, {lim, f}});
        b[r].push_back({l, {lim, f}});
    }
    cout << solve(1, N, H) << endl;
}