#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(n, -1);
    vector<int> cnt(n, 1);
    long long res = 0;

    auto root = [&](int x) {
        if (par[x] == -1)
            par[x] = x;
        while (x != par[x]) 
            x = par[x] = par[par[x]];
        return x;
    };

    auto merge = [&](int x, int y, int val) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        par[x] = y;
        res += 1LL * val  * cnt[x] * cnt[y];
        cnt[y] += cnt[x];
        return true; 
    };

    sort(a.rbegin(), a.rend());
    vector<bool> done(n);
    for (auto e : a) {
        int u = e.second;
        int val = e.first;
        for (int v : g[u]) {
            if (done[v])
                merge(u, v, val);
        }
        done[u] = true;
    }

    cout << setprecision(6) << fixed << res * 2.0 / (1LL * n * (n - 1)) << '\n';


    return 0;
}