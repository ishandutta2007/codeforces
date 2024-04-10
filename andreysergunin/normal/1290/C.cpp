#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 300300;

vector<int> g[MAXN];

int timer = 0;
int used[MAXN];
int t[MAXN];

void dfs(int v) {
    t[v] ^= 1;
    used[v] = timer;
    for (int u : g[v]) {
        if (used[u] != timer) {
            dfs(u);
        }
    }
}

string state;

int w[MAXN];
int p[MAXN];
int cost[MAXN];
int f[MAXN];
int xr[MAXN];

int get(int u) {
    return p[u] = (p[u] == u ? u : get(p[u]));
}

void unite(int u, int v, bool flag) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return;
    }

    if (w[u] < w[v]) {
        swap(u, v);
    }

    if (flag) {
        if (f[v]) {
            assert(!f[u]);
            xr[u] ^= 1;
            cost[u] = w[u] - cost[u];
        } else {
            xr[v] ^= 1;
            cost[v] = w[v] - cost[v];
        }
    }

    if (xr[u] != xr[v]) {
        ++timer;
        xr[v] ^= 1;
        dfs(v);
    }

    g[u].push_back(v);
    g[v].push_back(u);
    p[v] = u;
    w[u] += w[v];
    cost[u] += cost[v];
    f[u] |= f[v];

    if (!f[u] && 2 * cost[u] > w[u]) {
        xr[u] ^= 1;
        cost[u] = w[u] - cost[u];
    }
} 

void solve() {  
    int n, k;
    cin >> n >> k;
    cin >> state;
    vector<vector<int>> s(n);

    for (int i = 0; i < k; ++i) {
        w[i] = 1;
        p[i] = i;
    }

    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int v;
            cin >> v;
            --v;
            s[v].push_back(i);
        }
    }

    int total = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (sz(s[i]) == 1) {
            int u = s[i][0];
            int init = state[i] - '0';
            int v = get(u);
            if (!(t[u] ^ xr[v] ^ init)) {
                xr[v] ^= 1;
                total -= cost[v];
                cost[v] = w[v] - cost[v];
                total += cost[v];
            }
            f[v] = true;
        } else if (sz(s[i]) == 2) {
            int u = s[i][0], v = s[i][1];
            if (get(u) != get(v)) {  
                total -= cost[get(u)] + cost[get(v)];
                unite(u, v, xr[get(u)] ^ xr[get(v)] ^ t[u] ^ t[v] ^ (state[i] == '0'));
                total += cost[get(u)];
            } 
        }
        res.push_back(total);
    }

    for (int x : res) {
        cout << x << "\n";
    }
    cout << endl;
}