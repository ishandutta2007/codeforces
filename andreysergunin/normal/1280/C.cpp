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

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 200200;

vector<pii> g[MAXN];

int n;
ll lower = 0;
ll upper = 0;

int dfs(int v, int p = -1, int tt = 0) {
    int w = 1;

    for (auto [u, t] : g[v]) {
        if (u == p) {
            continue;
        }
        w += dfs(u, v, t);
    }

    if (w & 1) {
        lower += tt;
    }
    upper += ll(min(w, n - w)) * tt;

    return w;
}

void solve() {
    cin >> n;

    n *= 2;

    lower = 0;
    upper = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }

    dfs(0);

    cout << lower << " " << upper << endl;

    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}