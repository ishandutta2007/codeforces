#include <bits/stdc++.h>

using namespace std;

vector < int > g[300005];
int a[300005];
int dp[300005];
int k;

void dfs(int v){
    if ((int)g[v].size() == 0){
        dp[v] = 1;
        return;
    }
    if (a[v] == 0){
        for (auto u : g[v]) dfs(u), dp[v] += dp[u];
    }
    else{
        dp[v] = k;
        for (auto u : g[v]) dfs(u), dp[v] = min(dp[v], dp[u]);
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i){
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) if ((int)g[i].size() == 0) k++;
    dfs(1);
    cout << k + 1 - dp[1] << '\n';
    return 0;
}