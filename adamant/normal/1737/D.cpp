#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int d[n][n], g[n][n];
    memset(d, 0x3F, sizeof d);
    memset(g, 0x3F, sizeof g);
    //cout << d[0][0] << endl;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        int t = min(d[u][v], w);
        d[u][v] = d[v][u] = t;
        g[u][v] = g[v][u] = 1;
    }
    for(int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = 1e18;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(d[i][j] <= 1e9) {
                for(int k = 0; k < n; k++) {
                    int A = min(g[i][k], g[j][k]);
                    ans = min(ans, (1 + (A + 1) + g[0][k] + g[k][n - 1]) * d[i][j]);
                }
                ans = min(ans, (1 + g[0][i] + g[j][n - 1]) * d[i][j]);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //t = 10000;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}