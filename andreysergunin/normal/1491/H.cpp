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
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    int block = sqrtl(n);

    int m = (n + block - 1) / block;

    vector<int> f(n);
    for (int i = 1; i < n; ++i) {
        f[i] = (i / block == p[i] / block ? f[p[i]] : p[i]);
    }

    vector<int> final(m, false), g(m);
    auto update = [&](int l, int r, int id, int a) {
        int lf = id * block, rg = min(n, (id + 1) * block);
        if (final[id]) {
            if (l <= lf && rg <= r) {
                g[id] = min(g[id] + a, n);
            } else {
                for (int i = max(l, lf); i < min(r, rg); ++i) {
                    p[i] = max(p[i] - a, 0);
                }
            }
            return;
        }

        for (int i = max(l, lf); i < min(r, rg); ++i) {
            p[i] = max(p[i] - a, 0);
        }
        final[id] = true;
        for (int i = lf; i < rg; ++i) {
            final[id] &= p[i] / block != id;
            f[i] = (i / block == p[i] / block ? f[p[i]] : p[i]);
        }
    };

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, a;
            cin >> l >> r >> a;
            --l;
            for (int i = l / block; i <= (r - 1) / block; ++i) {
                update(l, r, i, a);
            }
        } else {
            int u, v;
            cin >> u >> v;
            --u; --v;

            while (u != v) {
                if (u > v) {
                    swap(u, v);
                }
                if (!final[v / block] && (u / block != v / block || f[u] != f[v])) {
                    v = max(0, f[v]);
                } else {
                    v = max(0, p[v] - g[v / block]);
                }
            }

            cout << u + 1 << "\n";
        }
    }

}