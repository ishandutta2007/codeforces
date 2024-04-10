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

const int MAXN = 200200;
vector<int> g[MAXN];
int w[MAXN];

vector<int> arr;
int dfs(int v, int p = -1) {
    arr.push_back(v);
    w[v] = 1;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        w[v] += dfs(u, v);
    }
    return w[v];
}

vector<int> f;

bool check(int root, int k) {
    arr.clear();
    dfs(root);
    if (sz(arr) != f[k]) {
        return false;
    }
    if (k <= 1) {
        return true;
    }

    for (int v : arr) {
        if (w[v] == f[k - 1] || w[v] == f[k - 2]) {
            int u;
            for (int uu : g[v]) {
                if (w[uu] > w[v]) {
                    u = uu;
                }
            }

            for (int i = 0; i < sz(g[u]); ++i) {
                if (g[u][i] == v) {
                    swap(g[u][i], g[u].back());
                    g[u].pop_back();
                    break;
                }
            }
            for (int i = 0; i < sz(g[v]); ++i) {
                if (g[v][i] == u) {
                    swap(g[v][i], g[v].back());
                    g[v].pop_back();
                    break;
                }
            }

            if (w[v] == f[k - 1]) {
                if (!check(v, k - 1)) {
                    return false;
                }
                if (!check(u, k - 2)) {
                    return false;
                }
            } else {
                if (!check(v, k - 2)) {
                    return false;
                }
                if (!check(u, k - 1)) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void solve() {  
    int n;
    cin >> n;

    int k = 2;
    f = {1, 1};
    for (; f.back() < n; ++k) {
        f.push_back(f[k - 2] + f[k - 1]);
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << (check(0, sz(f) - 1) ? "YES\n" : "NO\n");
}