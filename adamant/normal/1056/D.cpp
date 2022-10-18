#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 1e5 + 42;

vector<int> g[maxn];
int sz[maxn];

void dfs(int v = 0) {
    sz[v] = g[v].empty();
    for(auto u: g[v]) {
        dfs(u);
        sz[v] += sz[u];
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        g[p[i] - 1].push_back(i);
    }
    dfs();
    sort(sz, sz + n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, sz[i - 1]);
        cout << ans << ' ';
    }
    return 0;
}