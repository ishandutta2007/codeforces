#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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

const int MAXN = 100100;

vector<int> g[MAXN];
vector<pii> path;

void dfs(int v, int k, int lim, int p = -1) {
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        if (u == p) {
            swap(g[v][i], g[v].back());
            g[v].pop_back();
            break;
        }
    }

    int cur = k;
    int i = 0;
    for (; i < sz(g[v]) && cur < lim; ++i) {
        int u = g[v][i];
        path.push_back({u, ++cur});
        dfs(u, cur, lim, v);
        path.push_back({v, cur});
    }
    if (i == sz(g[v])) {
        if (k != 0) {
            path.push_back({v, k - 1});
        }
        return;
    }
    int rem = sz(g[v]) - i;
    assert(k - rem - 1 < cur);
    cur = k - rem - 1;
    assert(cur >= 0);
    path.push_back({v, cur});
    for (; i < sz(g[v]); ++i) {
        int u = g[v][i];
        path.push_back({u, ++cur});
        dfs(u, cur, lim, v);
        path.push_back({v, cur});
    }
    assert(cur == k - 1);
}

void solve() {  
    int n;
    cin >> n;
    // n = 100000;

    path.clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        // u = i + 1;
        // v = rnd() % u;
        // v = i == 0 ? 0 : (u - 2) / 2;
        // cerr << u << " " << v << endl;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    path.push_back({0, 0});

    int maxx = sz(g[0]);
    for (int i = 1; i < n; ++i) {
        maxx = max(maxx, sz(g[i]));
    }
    dfs(0, 0, maxx);

    assert(sz(path) <= 1e6);

    for (int i = 0; i < sz(path); ++i) {
        assert(path[i].second <= maxx);
    }

    cout << sz(path) << "\n";
    for (auto [x, y] : path) {
        cout << x + 1 << " " << y << "\n";
    }

    // sort(all(path));
    // set<pii> setik(path.begin(), path.end());
    // assert (sz(path) == sz(setik));
}