#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    set<pii> setik;
    vector<int> order;
    
    vector<int> t(n);
    vector<int> used(n);
    vector<int> deg(n);

    for (int i = 0; i < n; ++i) {
        deg[i] = sz(g[i]);
        setik.insert({deg[i], i});
        // cerr << deg[i] << " " << i << endl;
    }

    for (int i = 0; !setik.empty(); ++i) {
        auto it = setik.begin();
        auto [d, v] = *it;
        if (d >= k) {
            break;
        }
        setik.erase(it);
        used[v] = true;
        order.push_back(v);
        t[v] = i;

        for (int u : g[v]) {
            if (!used[u]) {
                setik.erase({deg[u], u});
                --deg[u];
                setik.insert({deg[u], u});
            }
        }
    }

    if (!setik.empty()) {
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                res.push_back(i);
            }
        }
        cout << 1 << " " << sz(res) << "\n";
        for (int v : res) {
            cout << v + 1 << " ";
        }
        cout << "\n";
        return;
    }

    // for (int v : order) {
    //     cout << v << " ";
    // }
    // cout << endl;

    for (int v : order) {
        vector<int> gg;
        for (int u : g[v]) {
            if (t[v] < t[u]) {
                gg.push_back(u);
            }            
        }
        g[v] = gg;

        // cout << v << " " << sz(g[v]) << endl;
    }

    vector<int> cnt(n);

    for (int v : order) {
        if (sz(g[v]) != k - 1) {
            continue;
        }
        for (int u : g[v]) {
            for (int w : g[u]) {
                ++cnt[w];
            }
        }
        ll sum = 0;
        for (int u : g[v]) {
            sum += cnt[u];
        }
        for (int u : g[v]) {
            for (int w : g[u]) {
                cnt[w] = 0;
            }
        }

        if (sum == ll(k - 2) * (k - 1) / 2) {
            cout << 2 << "\n";

            cout << v + 1 << " ";
            for (int u : g[v]) {
                cout << u + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }

    cout << -1 << "\n";


}