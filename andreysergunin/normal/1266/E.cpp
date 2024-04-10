#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 200100; 

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res += a[i];
    }

    int q;
    cin >> q;

    map<pii, int> mapa;

    for (int i = 0; i < q; ++i) {
        int s, t, u;
        cin >> s >> t >> u;
        --s; --u;

        if (mapa.count({s, t})) {
            int v = mapa[{s, t}];
            res -= max(a[v] - b[v], 0);
            --b[v];
            res += max(a[v] - b[v], 0);

            mapa.erase({s, t});
        }

        if (u != -1) {
            res -= max(a[u] - b[u], 0);
            ++b[u];
            res += max(a[u] - b[u], 0);

            mapa[{s, t}] = u;
        }

        cout << res << "\n";
    }
}