#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> pr(n), h(n);
        for (int i = 0; i < n; ++i) cin >> pr[i];
        for (int i = 0; i < n; ++i) cin >> h[i];
        vector <vector <int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector <int> r(n);

        function<void(int, int)> dfs1 = [&](int v, int p) {
            r[v] = pr[v];
            for (int i : g[v]) {
                if (i != p) {
                    dfs1(i, v);
                    r[v] += r[i];
                }
            }
        };

        dfs1(0, -1);

        vector <int> go(n), ba(n);
        bool f = false;

        for (int i = 0; i < n; ++i) {
            ba[i] = (r[i] - h[i]) / 2;
            go[i] = r[i] - ba[i];
            if (ba[i] + go[i] != r[i] || go[i] - ba[i] != h[i] || ba[i] < 0 || go[i] < 0) {
                cout << "NO\n";
                f = true;
                break;
            }
        }

        if (f) continue;

        function<bool(int, int)> check = [&](int v, int p) {
            int kolg = 0, kolb = 0;
            for (auto i : g[v]) {
                if (i != p) {
                    kolg += go[i];
                    kolb += ba[i];
                }
            }
            if (go[v] >= kolg) {
                for (auto i : g[v]) {
                    if (i != p) {
                        if (!check(i, v)) return false;
                    }
                }
                return true;
            }
            else return false;
        };

        if (check(0, -1)) cout << "YES\n";
        else cout << "NO\n";
    }
}