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
 
vector<int> g[MAXN];
 
int mod;
 
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
 
void mul(int &a, int b) {
    a = ll(a) * b % mod;
}

vector<int> used;

void dfs(int v, int col, int a, int b) {
    used[v] = col;
    for (int u : g[v]) {
        if (used[u] || u == a || u == b) {
            continue;
        }
        dfs(u, col, a, b);
    }
}
 
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a; --b;
    used.clear();
    used.resize(n, 0);
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int k = 1;

    for (int i = 0; i < n; ++i) {
        if (i == a || i == b) {
            continue;
        }
        if (!used[i]) {
             dfs(i, k++, a, b);
        }
    }

    vector<int> adj(k + 1);
    vector<int> cnt(k + 1);


    for (int i = 0; i < n; ++i) {
        if (i == a || i == b) {
            continue;
        }
        ++cnt[used[i]];
        for (int u : g[i]) {
            if (u == a) {
                adj[used[i]] |= 1;
            } 
            if (u == b) {
                adj[used[i]]  |= 2;
            }
        }
    }


    int x = 0, y = 0;
    for (int i = 1; i <= k; ++i) {
        if (adj[i] == 1) {
            x += cnt[i];
        }
        if (adj[i] == 2) {
            y += cnt[i];
        }
    }


    cout << ll(x) * y << endl; 
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}