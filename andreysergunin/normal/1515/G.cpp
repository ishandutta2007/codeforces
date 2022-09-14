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

vector<int> g[MAXN], len[MAXN];

int cols = 0;
int col[MAXN];

int used[MAXN];
int tin[MAXN], up[MAXN];
int timer = 0;

bool onStack[MAXN];

stack<int> st;

int scc(int v) {
    st.push(v);
    onStack[v] = true;
    used[v] = 1;

    tin[v] = ++timer;
    up[v] = tin[v];

    for (int u : g[v]) {
        if (!used[u]) {
            up[v] = min(up[v], scc(u));
        } else if (onStack[u]) {
            up[v] = min(up[v], tin[u]);
        }
    }

    if (tin[v] == up[v]) {
        while (st.top() != v) {
            col[st.top()] = cols;
            onStack[st.top()] = false;
            st.pop();
        } 
        col[st.top()] = cols;
        onStack[st.top()] = false;
        st.pop();
        ++cols;
    }

    return up[v];
} 

int usedcol[MAXN];
ll l[MAXN];

ll cycle(int v, ll s) {
    if (used[v]) {
        return s - l[v];
    }
    l[v] = s;
    used[v] = 1;
    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        if (col[u] == col[v]) {
            return cycle(u, s + len[v][i]);
        }
    }
    return 0;
}

ll f[MAXN];

void dfs(int v, ll s) {
    l[v] = s;
    used[v] = 1;
    int c = col[v];

    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];    
        if (col[u] != col[v]) { 
            continue;
        }
        if (used[u]) {
            ll x = l[u] % f[c];
            ll y = (s + len[v][i]) % f[c];
            f[c] = gcd(f[c], abs(x - y));
        } else {
            dfs(u, s + len[v][i]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        g[u].push_back(v);
        len[u].push_back(l);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            scc(i);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << col[i] << " ";
    // }
    // cout << endl;

    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        if (!usedcol[col[i]]) {
            usedcol[col[i]] = 1;
            f[col[i]] = cycle(i, 0);
        }
    }

    // for (int i = 0; i < cols; ++i) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;

    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }

    // for (int i = 0; i < cols; ++i) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int v, s, t;
        cin >> v >> s >> t;
        s = (t - s) % t;
        --v;

        if (!f[col[v]]) {
            cout << (s == 0 ? "YES\n" : "NO\n");
            continue;
        }

        ll step = gcd(f[col[v]], t);
        if (s % step == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}