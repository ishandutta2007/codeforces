#include <bits/stdc++.h>

using namespace std;

#define int long long

vector < pair < int, int > > g[200005];
int dp[200005];
int cnt[200005];
int node[200005];
int rev[200005];
int ans;

void dfs(int v, int p){
    for (auto u : g[v]){
        if (u.first == p) continue;
        dfs(u.first, v);
        int to = u.first;
        if (u.second == 1) dp[v] += dp[to] + 1;
        if (u.second == 0) cnt[v] += cnt[to] + 1;
        if (u.second == 1){
            node[v] += (node[to] + cnt[to]);
        }
        if (u.second == 0){
            rev[v] += (rev[to] + dp[to]);
        }
    }
    for (auto u : g[v]){
        if (u.first == p) continue;
        int to = u.first;
        int w = dp[v];
        if (u.second == 1) w -= (dp[to] + 1);
        if (u.second == 1) ans += w * (cnt[to] + node[to]);
        else ans += w * (cnt[to] + 1);
        w = rev[v];
        if (u.second == 0) w -= (rev[to] + dp[to]);
        if (u.second == 0) ans += w * (cnt[to] + 1);
    }
    for (auto u : g[v]){
        if (u.first == p) continue;
        int w = cnt[v];
        if (u.second == 0){
            w -= (cnt[u.first] + 1);
            ans += w * (cnt[u.first] + 1);
        }
        w = dp[v];
        if (u.second == 1){
            w -= (dp[u.first] + 1);
            ans += w * (dp[u.first] + 1);
        }
    }
    ans += (2 * dp[v] + 2 * cnt[v] + node[v] + rev[v]);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v, u, c;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}