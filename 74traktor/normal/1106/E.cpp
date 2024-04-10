#include <bits/stdc++.h>

using namespace std;

#define int long long
#define emplace_back push_back

const int MAXN = 1e5 + 10, MAXM = 210;

int dp[MAXN][MAXM];
pair < int, int > answ[100005];
int inf = 1e15;
vector < vector < int > > open[100005];
vector < vector < int > > close[100005];

void solve(int n){
    set < vector < int > > Q;
    for (int i = 1; i <= n; ++i){
        for (auto key : open[i]){
            Q.insert({key[2], key[1], i, key[0]});
        }
        if (Q.size() == 0) answ[i] = {-1, -1};
        else answ[i] = {(*Q.rbegin())[1], (*Q.rbegin())[0]};
        for (auto key : close[i]) Q.erase({key[2], key[1], key[0], i});
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXM; ++j) dp[i][j] = inf;
    int n, m, k, s, t, d, w;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i){
        cin >> s >> t >> d >> w;
        open[s].push_back({t, d, w});
        close[t].push_back({s, d, w});
    }
    solve(n);
    dp[1][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (answ[i].first == -1){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
            else{
                dp[answ[i].first + 1][j] = min(dp[answ[i].first + 1][j], dp[i][j] + answ[i].second);
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
        }
    }
    int ans = inf;
    for (int j = 0; j <= m; ++j) ans = min(ans, dp[n + 1][j]);
    cout << ans << '\n';
    return 0;
}