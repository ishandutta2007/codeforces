#include <bits/stdc++.h>

using namespace std;

vector < int > g[100005];
int cnt = 0;
int dp[100005];

void dfs(int v, int p) {
    int child = 0;
    for (auto u : g[v]) {
        if (u == p) continue;
        child++;
        dfs(u, v);
        dp[v] += dp[u];
    }
    if (child == 1 && p != 0) {
        cout << "NO" << '\n';
        exit(0);
    }
    if (child == 0) cnt++;
    else if (child == 1 && p == 0) cnt++;
    if (child == 0) dp[v] = 1;
}

void go(int v, int p) {
    int child = 0;
    for (auto u : g[v]) {
        if (u == p) continue;
        go(u, v);
        child++;
    }
    if (child == 2 && dp[v] == cnt) {
        cout << "NO" << '\n';
        exit(0);
    }
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    go(1, 0);
    if (cnt <= 2 && n != 2) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    return 0;
}