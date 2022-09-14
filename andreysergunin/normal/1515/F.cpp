#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";s
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 300300;

struct Edge {
    int u, v;
};

ll a[MAXN];
ll x;
vector<Edge> edges;

vector<int> g[MAXN];

int p[MAXN];

int get(int v) {
    return p[v] = (p[v] == v ? v : get(p[v]));
}

bool unite(int u, int v) {
    u = get(u); v = get(v);
    if (u == v) {
        return false;
    }
    p[u] = v;
    return true;
}

vector<int> res0, res1;

void dfs(int v, int p = -1) {
    for (int e : g[v]) {
        if (e != p) {
            int u = edges[e].u + edges[e].v - v;
            dfs(u, e);
        }
    }
    if (p != -1) {
        if (a[v] < x) {
            res1.push_back(p);
        } else {
            int u = edges[p].u + edges[p].v - v;
            a[u] += a[v] - x;
            res0.push_back(p); 
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m >> x;

    ll sum = 0; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    iota(p, p + n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges.push_back({u, v});

        if (unite(u, v)) {
            g[u].push_back(i);
            g[v].push_back(i);
        }
    }

    if (sum < x * (n - 1)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    dfs(0);

    for (int x : res0) {
        cout << x + 1 << " ";
    }
    reverse(all(res1));
    for (int x : res1) {
        cout << x + 1 << " ";
    }
    cout << endl;


}