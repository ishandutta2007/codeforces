#include <bits/stdc++.h>

using namespace std;

#define int long long

int w[300005];
int ans;
vector < pair < int, int > > g[300005];
int use[300005];
int dp[300005];

void dfs(int v){
    use[v] = 1;
    multiset < int > prom;
    for (auto key : g[v]){
        if (use[key.first] == (long long)0){
            dfs(key.first);
            if (dp[key.first] - key.second >= 0){
                dp[v] = max(dp[v], dp[key.first] + w[v] - key.second);
                prom.insert(dp[key.first] + w[v] - key.second);
            }
        }
    }
    if (prom.size() > 1){
        int tr = (*prom.rbegin());
        prom.erase(prom.find(tr));
        int tl = (*prom.rbegin());
        prom.erase(prom.find(tl));
        if (tr + tl - w[v] >= 0) ans = max(ans, tr + tl - w[v]);
    }
    ans = max(ans, dp[v]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) dp[i] = w[i];
    for (int i = 0; i < n - 1; ++i){
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}