#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> arr(n, vector<string>(n));
    for (int i = 0; i < n; ++i) {
        arr[i][i] = string(n, '1');
        for (int j = i + 1; j < n; ++j) {
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }

    vector<vector<vector<int>>> layers(n);
    for (int k = 0; k < n; ++k) {
        vector<int> used(n);
        used[k] = 1;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            vector<int> layer;
            for (int j = i; j < n; ++j) {
                if (arr[i][j][k] == '1') { 
                    layer.push_back(j);
                    used[j] = true;
                }
            }
            layers[k].push_back(layer);
            // cout << k << " -> ";
            // for (int u : layer) {
            //     cout << u << " ";
            // }
            // cout << endl;
        }
    }

    vector<int> used(n);
    vector<pii> edges;

    function<void(int, int)> dfs = [&](int v, int neighbour) {
        used[v] = true;
        for (int i = 0; i < sz(layers[v]); ++i) {
            bool ok = false;
            for (int u : layers[v][i]) {
                ok |= u == neighbour;
            }
            if (!ok) {
                continue;
            }
            for (int u : layers[v][i]) {
                if (!used[u]) {
                    dfs(u, v);
                }
                edges.emplace_back(min(u, v), max(u, v));
            }
        }
    };

    vector<vector<int>> g(n);
    vector<vector<int>> dist(n, vector<int>(n));

    function<void(int, int, int, int)> calc_dist = [&](int v, int p, int start, int d) {
        dist[start][v] = d;
        for (int u : g[v]) {
            if (u == p) {
                continue;
            }
            calc_dist(u, v, start, d + 1);
        }
    };

    auto check = [&]() {
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        for (auto [u, v] : edges) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            calc_dist(i, -1, i, 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((arr[i][j][k] == '1') ^ (dist[i][k] == dist[j][k])) {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    for (int k = 0; k < sz(layers[0]); ++k) {
        used.assign(n, 0);
        edges.clear();
        dfs(0, layers[0][k][0]);
        sort(all(edges));
        edges.resize(unique(all(edges)) - edges.begin());
        bool ok = sz(edges) == n - 1;
        for (int i = 0; i < n; ++i) {
            ok &= used[i];
        }
        if (ok && check()) {
            cout << "Yes\n";
            for (auto [u, v] : edges) {
                cout << u + 1 << " " << v + 1 << "\n";
            }
            return;
        }
    }   

    cout << "No\n";
}