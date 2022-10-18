#include <bits/stdc++.h>

using namespace std;

int mx[500005];
vector < int > g[500005];
int used[500005];
int dp[500005][20];

void dfs(int v, int p){
    used[v] = 1;
    dp[v][0] = p;
    for (int i = 1; i <= 19; ++i){
        int to = dp[v][i - 1];
        dp[v][i] = dp[to][i - 1];
    }
    for (auto u : g[v]){
        if (used[u] == 0) dfs(u, v);
    }
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> l >> r;
        mx[l] = max(mx[l], r);
    }
    for (int i = 1; i <= 500000; ++i){
        mx[i] = max(mx[i], mx[i - 1]);
    }
    for (int i = 0; i <= 500000; ++i){
        if (mx[i] > i) g[mx[i]].push_back(i);
    }
    //for (int i = 0; i <= 10; ++i) cout << mx[i] << " ";
    //cout << endl;
    //for (int i = 500000; i >= 0; --i) if (used[i] == 0) dfs(i, 0);
    for (int i = 500000; i >= 0; --i){
        if (mx[i] > i){
            dp[i][0] = mx[i];
            for (int j = 1; j <= 19; ++j) dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    for (int q = 1; q <= m; ++q){
        cin >> x >> y;
        int ans = 0;
        for (int i = 19; i >= 0; --i){
            if (dp[x][i] < y && dp[x][i] > x){
                ans += (1<<i);
                x = dp[x][i];
            }
        }
        if (x < y && mx[x] < y){
            cout << -1 << '\n';
        }
        else cout << ans + 1 << '\n';
    }
    return 0;
}