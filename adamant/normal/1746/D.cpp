#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n, k;
    n = 2e5;
    k = 1e9;
    cin >> n >> k;
    vector<int> g[n];
    int s[n], p[n];
    for(int i = 1; i < n; i++) {
        p[i] = rand() % i + 1;
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        s[i] = rand() % 10;
        cin >> s[i];
    }
    
    //map<pair<int, int>, int> cache;
    map<int, int> cache[n];
    int mx = 0;
    auto dfs = [&g, &s, &mx, &cache](int v, int k, auto&& dfs) -> int {
        mx = max(mx, (int)cache[v].size());
        if(cache[v].count(k) || k == 0) {
            return cache[v][k];
        }
        if(g[v].empty()) {
            return k * s[v];
        }
        int m = g[v].size();
        int t = k / m;
        int d[m][2], df[m];
        int extra = k % m;
        for(int i = 0; i < m; i++) {
            d[i][0] = dfs(g[v][i], t, dfs);
            if(extra) {
                d[i][1] = dfs(g[v][i], t + 1, dfs);
            } else {
                d[i][1] = 0;
            }
            df[i] = d[i][1] - d[i][0];
        }
        int p[m];
        iota(p, p + m, 0);
        sort(p, p + m, [&](int a, int b) {
            return df[a] > df[b];
        });
        int res = k * s[v];
        for(int i = 0; i < m; i++) {
            res += d[p[i]][i < extra];
        }
        return cache[v][k] = res;
    };
    int res = dfs(0, k, dfs);
    //cout << mx << "\n";
    cout << res << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    //return 0;
}