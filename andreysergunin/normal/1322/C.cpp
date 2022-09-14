#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
    int tests = 1;
    cin >> tests;
 
    while (tests--) {
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
    vector<ll> c(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[v].push_back(u);
    }
//  
    vector<int> p(n);
    iota(all(p), 0);
 
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }
    auto cmp = [&](int i, int j) {
        return g[i] < g[j];
    };
    sort(all(p), cmp);
 
    ll res = 0;
    ll cur = c[p[0]];
    for (int i = 1; i < n; ++i) {
        if (g[p[i]] == g[p[i - 1]]) {
            cur += c[p[i]];
        } else {
            if (!g[p[i - 1]].empty() ) {
                res = gcd(res, cur);
            }
            cur = c[p[i]];
        }
    }
    res = gcd(res, cur);
    cout << res << "\n";
}