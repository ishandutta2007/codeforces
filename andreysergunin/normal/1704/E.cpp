#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
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
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int mod = 998244353;

void mul(int &a, int b) {
    a = ll(a) * b % mod;
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

vector<vector<int>> g;
vector<int> order;
vector<int> used;

void dfs(int v) {   
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    } 
    order.push_back(v);
}

void solve() {  

    g.clear();
    order.clear();
    used.clear();

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    g.assign(n, {});
    used.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }    

    for (int u = 0; u < n; ++u) {
        if (!used[u]) {
            dfs(u);
        }
    }   
    int res = 0;
    vector<int> cnt(n);
    cnt[order[0]] = 1;
    for (int v : order) {
        for (int u : g[v]) {
            add(cnt[v], cnt[u]);
        }
        int x = cnt[v];
        mul(x, a[v]);
        add(res, x);
    }

    for (int i = 0; i <= n; ++i) {
        add(res, a[order[0]] == 0); 
        vector<int> good;
        for (int j = 0; j < n; ++j) {
            if (a[j]) {
                good.push_back(j);
            }
        }
        if (sz(good) == 0) {
            cout << i << endl;
            return;
        }
        for (int v : good) {
            --a[v];
            for (int u : g[v]) {
                ++a[u];                
            }
        }
    }
    cout << res << endl;
}