#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> a(n);
    for (int i = 0; i + 1 < n; ++i) {
        a[i].resize(n - i - 1);
        for (int j = 0; j < n - i - 1; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        vector<int> pr(n, -1);
        pr[0] = i, pr[i] = 0;
        queue<int> q;
        q.push(0);
        q.push(i);
        vector<vector<int>> g(n);
        g[0].push_back(i);
        g[i].push_back(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < n; ++j) {
                if (pr[j] == -1 && a[min(pr[v], j)][max(pr[v], j) - min(pr[v], j) - 1][v] == '1') {
                    g[v].push_back(j);
                    g[j].push_back(v);
                    pr[j] = v;
                    q.push(j);
                }
            }
        }
        bool ch = true;
        for (int j = 0; j < n; ++j) {
            if (pr[j] == -1) {
                ch = false;
            }
        }
        if (!ch) {
            continue;
        }
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for (int j = 0; j < n; ++j) {
            dist[j][j] = 0;
            q.push(j);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto u : g[v]) {
                    if (dist[j][u] == -1) {
                        dist[j][u] = dist[j][v] + 1;
                        q.push(u);
                    }
                }
            }
        }
        for (int v1 = 0; v1 < n; ++v1) {
            for (int v2 = v1 + 1; v2 < n; ++v2) {
                for (int v3 = 0; v3 < n; ++v3) {
                    if ((dist[v1][v3] == dist[v2][v3] && a[v1][v2 - v1 - 1][v3] == '0') || (dist[v1][v3] != dist[v2][v3] && a[v1][v2 - v1 - 1][v3] == '1')) {
                        ch = false;
                        break;
                    }
                }
                if (!ch) {
                    break;
                }
            }
            if (!ch) {
                break;
            }
        }
        if (ch) {
            cout << "Yes\n";
            for (int v = 0; v < n; ++v) {
                for (auto u : g[v]) {
                    if (v < u) {
                        cout << v + 1 << ' ' << u + 1 << '\n';
                    }
                }
            }
            return;
        }
    }
    cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}