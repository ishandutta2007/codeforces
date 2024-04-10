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
 
const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

const int MAXN = 500500;

vector<int> g[MAXN];
int p[MAXN];

int used[2 * MAXN];
int par[MAXN];
int tin[MAXN], tout[MAXN];

vector<pii> e[MAXN];
int fst[MAXN], lst[MAXN];
int timer = 0;

void nie() {
    cout << 0 << endl;
    exit(0);
}
 
void dfs(int v, int p = -1) {
    tin[v] = timer++;
    par[v] = p;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
    tout[v] = timer++;
}

bool parent(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void getPath(int u, int v) {
    if (fst[u] != -1 || lst[v] != -1) {
        nie();
    }
    vector<int> path = {u};
    while (!parent(u, v)) {
        if (used[2 * u]) {
            nie();
        }
        used[2 * u] = 1;
        u = par[u];
        path.push_back(u);
    }
    int k = sz(path);
    while (v != u) {
        if (used[2 * v + 1]) {
            nie();
        }
        used[2 * v + 1] = 1;
        path.push_back(v);
        v = par[v];
    }

    reverse(path.begin() + k, path.end());
    k = sz(path);
    fst[path[0]] = path[1];
    lst[path[k - 1]] = path[k - 2];

    for (int i = 1; i + 1 < sz(path); ++i) {
        e[path[i]].push_back({path[i - 1], path[i + 1]});
    }
}

int in[MAXN], out[MAXN];
int to[MAXN];
int vis[MAXN];
int fact[MAXN];

int solve(int v) {
    for (auto [x, y] : e[v]) {
        ++out[x];
        ++in[y];
        to[x] = y;
    }   

    if (fst[v] != -1 && in[fst[v]] != 0) {
        nie();
    }

    vector<int> st;
    for (int u : g[v]) {
        if (in[u] > 1 || out[u] > 1) {
            nie();
        }
        if (in[u] == 0) {
            st.push_back(u);
        }
    }

    bool ok = (lst[v] == -1);
    bool bad = false;

    int cnt = 0;
    for (int u : st) {
        if (vis[u]) {
            continue;
        }
        ++cnt;
        int cur = u;
        vis[cur] = 1;
        while (out[cur] == 1) {
            cur = to[cur];
            vis[cur] = 1;
        }
        if (lst[v] == cur) {
            if (u == fst[v]) {
                bad = true;
            }
            ok = true;
        }
    }
    if (!ok || (cnt > 1 && bad)) {
        nie();
    }
    for (int u : g[v]) {
        if (!vis[u]) {
            nie();
        }
    }

    for (int u : g[v]) {
        in[u] = 0;
        out[u] = 0;
        vis[u] = 0;
    }

    int x = cnt - (fst[v] != -1) - (lst[v] != -1);

    return fact[max(0, x)];
}

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
    
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(fst, -1, sizeof(fst));
    memset(lst, -1, sizeof(lst));

    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }

    dfs(0);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }


    for (int i = 0; i < n; ++i) {
        if (p[i] == i) {
            cout << 0 << endl;
            return 0;
        }
        if (p[i] != -1) {
            getPath(i, p[i]);
        }
    }

    int res = 1;
    for (int i = 0; i < n; ++i) {
        mul(res, solve(i));
    }

    cout << res << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}