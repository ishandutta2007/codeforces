#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

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
    int n, m;
    cin >> n >> m;

    int x = 0;
    vector<array<int, 3>> edges;
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u, v, w});
        x ^= w;
        g[u].insert(v);
        g[v].insert(u);
    }
    sort(all(edges), [](const array<int, 3> &a, const array<int, 3> &b) {return a[2] < b[2]; });

    set<int> used;
    for (int i = 0; i < n; ++i) {
        used.insert(i);
        g[i].insert(-1);
    }
    
    vector<int> col(n);

    vector<pii> bad;

    function<void(int, int)> dfs = [&](int v, int c) {
        used.erase(v);
        col[v] = c;
        for (int lf : g[v]) {
            auto it = g[v].upper_bound(lf);
            int rg = (it == g[v].end() ? n : *it);

            while (true) {
                auto it = used.upper_bound(lf);
                if (it == used.end() || *it >= rg) {
                    break;
                }
                bad.push_back({v, *it});
                dfs(*it, c);
            }
        }
    };

    int k = 0;

    while (!used.empty()) {
        int v = *used.begin();
        dfs(v, k++);
    }


    vector<int> p(n), w(n, 1);
    iota(all(p), 0);

    function<int(int)> get = [&](int v) {
        return p[v] == v ? v : get(p[v]);
    };

    auto merge = [&](int v, int u) {
        u = get(u); v = get(v);
        if (u == v) {
            return false;
        }
        if (w[u] > w[v]) {
            swap(u, v);
        }
        p[u] = v;
        w[v] += w[u];
        return true;
    };


    ll rem = ll(n) * (n - 1) / 2 - m;

    ll res = 0;

    for (auto [u, v, w] : edges) {
        if (merge(col[u], col[v])) {
            res += w;
        }
    }

    if (rem + k != n) {
        cout << res << endl;
        return;
    }

    res += x;

    for (auto [uu, vv] : bad) {
        auto cp = edges;
        array<int, 3> e = {uu, vv, x};
        auto it = lower_bound(all(cp), e, [](const array<int, 3> &a, const array<int, 3> &b) {return a[2] < b[2]; });
        cp.insert(it, e);

        iota(all(p), 0);
        w.assign(n, 1);

        for (auto [u, v] : bad) { 
            if (u == uu && v == vv) {
                continue;
            }
            merge(u, v);
        }

        ll cur = 0;
        for (auto [u, v, w] : cp) {
            if (merge(u, v)) {
                cur += w;
            }
        }

        res = min(res, cur);
    }

    cout << res << endl;

}