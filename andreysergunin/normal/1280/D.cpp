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

const int MAXN = 3030;

vector<int> g[MAXN];

pair<int, ll> dp[MAXN][MAXN];
ll delta[MAXN];
int w[MAXN];
int n;

int dfs(int v, int p = -1) {
    w[v] = 1;

    dp[v][0] = {0, delta[v]};
    for (int i = 1; i <= n; ++i) {
        dp[v][i] = {-1, 0};
    }

    vector<pair<int, ll>> nxt;

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);

        nxt.resize(w[v] + w[u]);
        nxt.assign(w[v] + w[u], {-1, 0});

        for (int i = 0; i < w[v]; ++i) {
            for (int j = 0; j < w[u]; ++j) {
                pair<int, ll> p;
                p.first = dp[v][i].first + dp[u][j].first;
                p.second = dp[v][i].second + dp[u][j].second;
                nxt[i + j] = max(nxt[i + j], p);

                p.first = dp[v][i].first + dp[u][j].first + (dp[u][j].second > 0);
                p.second = dp[v][i].second;
                nxt[i + j + 1] = max(nxt[i + j + 1], p);
            }
        }

        for (int i = 0; i < sz(nxt); ++i) {
            dp[v][i] = nxt[i];
        }

        w[v] += w[u];
    }

    return w[v];
}

void solve() {
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        delta[i] -= x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        delta[i] += x;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    // cerr << dp[0][m - 1].first << " " << dp[0][m - 1].second << endl;

    int res = dp[0][m - 1].first + (dp[0][m - 1].second > 0);

    cout << res << endl;

    for (int i = 0; i < n; ++i) {
        g[i].clear();
        delta[i] = 0;
    }
}