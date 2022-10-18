#include <bits/stdc++.h>

using namespace std;

vector < int > g[1000005];
int dp[1000005];
int used[1000005];
int n;
int tmp, sz;

void dfs(int v){
    used[v] = tmp;
    if (v <= n) sz++;
    for (auto u : g[v]){
        if (used[u] == 0) dfs(u);
    }
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, k, x;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> k;
        for (int j = 1; j <= k; ++j){
            cin >> x;
            g[x].push_back(n + i);
            g[n + i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i){
        if (used[i] == 0){
            tmp++;
            sz = 0;
            dfs(i);
            dp[tmp] = sz;
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << dp[used[i]] << " ";
    }
    return 0;
}