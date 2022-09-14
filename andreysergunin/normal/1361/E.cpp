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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    cin >> tests;
 
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
int used[MAXN];

bool dfs(int v) {
    used[v] = 1;

    for (int u : g[v]) {
        if (used[u] == 2) {
            return false;
        } else if (!used[u] && !dfs(u)) {
            return false;
        }
    }

    used[v] = 2;

    return true;
}

int good[MAXN];
int up[MAXN][2];
int tin[MAXN];
int timer = 0;
int f[MAXN];

void update(int v, int x) {
    if (x == 0 || tin[v] == x) {
        return;
    }
    if (up[v][0] == 0 || up[v][0] > x) {
        up[v][1] = up[v][0];
        up[v][0] = x;
    } else if (up[v][1] == 0 || up[v][1] > x) {
        up[v][1] = x;
    }
}

void dfs1(int v) {
    used[v] = 1;    

    tin[v] = ++timer;
    f[tin[v]] = v;

    for (int u : g[v]) {
        if (!used[u]) {
            dfs1(u);
            update(v, up[u][0]);
            update(v, up[u][1]);
        } else {
            update(v, tin[u]);
        }
    } 
}

void dfs2(int v) {
    used[v] = 1;    

    good[v] = true;
    if (up[v][1] != 0 || up[v][0] == 0) {
        good[v] = false;
    } else {
        good[v] = good[f[up[v][0]]];
    }

    for (int u : g[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }

}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    } 


    int root = -1;
    for (int t = 0; t < 100; ++t) {
        memset(used, 0, sizeof(int) * n);

        int v = rnd() % n;
        if (dfs(v)) {
            root = v;
            break;
        }
    }

    if (root == -1) {
        cout << "-1\n";
        return;
    }
    
    timer = 0;


    memset(used, 0, sizeof(int) * n);
    memset(up, 0, sizeof(up[0]) * n);
    dfs1(root);

    up[root][0] = tin[root];

    memset(used, 0, sizeof(int) * n);
    memset(good, 0, sizeof(int) * n);
    
    dfs2(root);

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            res.push_back(i);
        }
    }

    if (sz(res) * 5 >= n) {
        for (int v : res) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}