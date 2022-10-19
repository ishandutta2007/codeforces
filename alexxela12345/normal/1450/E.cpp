//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<int>> d(n, vector<int> (n, INF));
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        g[a].push_back({b, 1});
        d[a][b] = 1;
        if (t == 0) {
            g[b].push_back({a, 1});
            d[b][a] = 1;
        } else {
            g[b].push_back({a, -1});
            d[b][a] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i][k] != INF) {
                for (int j = 0; j < n; j++) {
                    if (d[k][j] != INF && d[i][j] > -INF) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
    }
    int max_ans = -1;
    int max_pos = -1;
    bool bad = false;
    for (int i = 0; i < n; i++)
        if (d[i][i] < 0)
            bad = 1;
    for (int i = 0; i < n && !bad; i++) {
        if (d[i][i] < 0)
            continue;
        bool good = true;
        for (int u = 0; u < n; u++) {
            for (auto e : g[u]) {
                if (abs(d[i][u] - d[i][e.first]) != 1) {
                    good = false;
                    break;
                }
            }
        }
        if (!good) {
            continue;
        }
        for (int u = 0; u < n; u++) {
            if (d[i][u] < 0) {
                good = false;
                break;
            }
        }
        if (!good)
            continue;
        int max_x = *max_element(d[i].begin(), d[i].end());
        if (max_x > max_ans) {
            max_ans = max_x;
            max_pos = i;
        }
    }
    if (max_ans == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << max_ans << endl;
        for (int el : d[max_pos]) {
            cout << el << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    //cin >> tests;
    while (tests--) {
        solve();
    }
}