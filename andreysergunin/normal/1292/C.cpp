#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

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

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 3030;
vector<int> g[MAXN];
ll w[MAXN];
ll dp[MAXN][MAXN];
int par[MAXN];
int n;

int dfs(int v, int p = -1) {
    w[v] = 1;
    par[v] = p;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        w[v] += dfs(u, v);
    }
    return w[v];
}


vector<int> dfs_calc(int v, int p = -1) {
    vector<int> subtree = {v};
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        vector<int> cur = dfs_calc(u, v);
        for (int t : cur) {
            dp[v][t] = max(dp[u][t], dp[v][par[t]]) + (n - w[u]) * w[t];
            dp[t][v] = dp[v][t];
        }
        for (int s : subtree) {
            if (s == v) {
                continue;
            }
            for (int t : cur) {
                dp[s][t] = max(dp[s][par[t]], dp[t][par[s]]) + w[s] * w[t];
                dp[t][s] = dp[s][t];
            }   
        }
        for (int t : cur) {
            subtree.push_back(t);
        }
    }
    return subtree;
}


void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    dfs_calc(0);

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // cout << dp[i][j] << " ";
            res = max(res, dp[i][j]);
        }
        // cout << endl;
    }

    cout << res << endl;
}