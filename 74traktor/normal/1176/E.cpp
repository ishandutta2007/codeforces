#include <bits/stdc++.h>

using namespace std;

vector < int > g[200005];
vector < int > G[200005];
int used[200005];
int dp[200005][3];
vector < int > out;

void dfs(int v){
    used[v] = 1;
    for (auto u : g[v]){
        if (used[u] == 1) continue;
        G[v].push_back(u);
        dfs(u);
    }
}

void dfs1(int v){
    if ((int)G[v].size() == 0){
        dp[v][0] = 0;
        dp[v][1] = 1;
        dp[v][2] = 1;
        return;
    }
    int sum = 0;
    dp[v][1] = 1;
    for (auto u : G[v]){
        dfs1(u);
        dp[v][1] += min({dp[u][0], dp[u][1], dp[u][2]});
        sum += dp[u][2];
    }
    dp[v][2] = 1e9;
    for (auto u : G[v]){
        dp[v][2] = min(dp[v][2], sum - dp[u][2] + dp[u][1]);
    }
    dp[v][0] = sum;
    //cout << v << " " << dp[v][0] << " " << dp[v][1] << " " << dp[v][2] << endl;
}

void dfs2(int v, int k){
    if ((int)G[v].size() == 0 && k == 2){
        out.push_back(v);
        return;
    }
    if (k == 1) out.push_back(v);
    if (k == 0){
        for (auto u : G[v]) dfs2(u, 2);
    }
    else if (k == 1){
        for (auto u : G[v]){
            int h = min({dp[u][0], dp[u][1], dp[u][2]});
            for (int j = 0; j < 3; ++j){
                if (dp[u][j] == h){
                    dfs2(u, j);
                    break;
                }
            }
        }
    }
    else{
        int sum = 0;
        for (auto u : G[v]) sum += dp[u][2];
        int no = -1;
        for (auto u : G[v]){
            if (dp[v][k] == sum - dp[u][2] + dp[u][1]){
                dfs2(u, 1);
                no = u;
                break;
            }
        }
        for (auto u : G[v]) if (u != no) dfs2(u, 2);
    }
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, u, v;
    cin >> t;
    for (int q = 1; q <= t; ++q){
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) g[i] = {}, G[i] = {}, used[i] = 0;
        for (int i = 1; i <= m; ++i){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        out = {};
        dfs1(1);
        if (dp[1][1] < dp[1][2]) dfs2(1, 1);
        else dfs2(1, 2);
        if (n == 3 && (int)out.size() > 1) cout << 1 / 0 << endl;
        cout << out.size() << '\n';
        for (auto key : out) cout << key << " ";
        cout << '\n';
    }
    return 0;
}