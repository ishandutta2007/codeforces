#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

#define int long long
int const maxn = 18;
gp_hash_table < int, int > dp[(1 << maxn)], sum[(1 << maxn)];
int g[maxn][maxn];
int mod = 998244353;
int good[(1 << maxn)][maxn];
int go[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u][v] = 1;
        go[u] = (go[u]|(1 << v));
        go[v] = (go[v]|(1 << u));
    }
    dp[0][(1 << n) - 1] = 1, sum[0][(1 << n) - 1] = 0;
    for (int i = 0; i < (1 << n) - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int z = 0; z < n; ++z) {
                if ((i&(1 << z)) > 0) good[i][j] += g[z][j];
            }
        }
        int I = 0;
        for (int j = 0; j < n; ++j) {
            if ((i&(1 << j)) == 0) I += (1 << j);
        }
        for (auto key : dp[i]) {
            int pref = 0;
            int mask = key.first, cnt = key.second % mod, tmp = sum[i][mask];
            for (int j = 0; j < n; ++j) {
                if ((mask&(1 << j)) > 0) {
                    pref += (1 << j);
                    int to = ((mask^pref)|(I&go[j]));
                    int nxt = i + (1 << j), cost = good[i][j];
                    dp[nxt][to] += cnt;
                    sum[nxt][to] = (sum[nxt][to] + tmp + cnt * cost) % mod;
                }
            }
        }
    }
    cout << sum[(1 << n) - 1][0] << '\n';
    return 0;
}