#include <bits/stdc++.h>

using namespace std;

vector <int> a;
vector <vector<int>> g;
vector <int> dp;
vector <int> ans;

void dfs(int v, int p) {
    dp[v] = a[v];
    for (auto &to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        dp[v] += max(0, dp[to]);
    }
}

void dfs1(int v, int p) {
    ans[v] = dp[v];
    if (p != -1) {
        if (dp[v] >= 0) {
            ans[v] = max(ans[v], ans[p]);
        } else {
            ans[v] = max(ans[v], ans[p] + dp[v]);
        }
    }
    for (auto &to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    g.resize(n);
    dp.assign(n, -1);
    ans.resize(n);
    for (auto &c : a) {
        cin >> c;
        if (c == 0) {
            c = -1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    dfs1(0, -1);
    for (auto &c : ans) {
        cout << c << " ";
    }
    return 0;
}