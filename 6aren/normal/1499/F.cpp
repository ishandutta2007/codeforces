#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 998244353;

int dp[N][N], pref[N][N];
int n, k;
vector<int> g[N];

void dfs(int u, int p) {
    for (int e : g[u]) {
        if (e == p) continue;
        dfs(e, u);
    }
    dp[u][0] = 1;
    for (int e : g[u]) {
        if (e == p) continue;
        dp[u][0] = 1LL * dp[u][0] * pref[e][k] % MOD; 
    }
    pref[u][0] = dp[u][0];
    for (int i = 1; i <= k / 2; i++) {
        pref[u][i] = 1;
        for (int e : g[u]) {
            if (e == p) continue;
            pref[u][i] = 1LL * pref[u][i] * (pref[e][i - 1] + pref[e][k]) % MOD;
        }
        dp[u][i] = (pref[u][i] - pref[u][i - 1] + MOD) % MOD;
    }
    for (int i = k / 2 + 1; i <= k; i++) {
        // cout << u << ' ' << i << endl;
        dp[u][i] = 0;
        vector<int> pr(g[u].size(), 1);
        vector<int> su(g[u].size(), 1);
        for (int j = 0; j < g[u].size(); j++) {
            int e = g[u][j];
            int foo = (e == p ? 1 : ((k - i - 1 >= 0 ? pref[e][k - i - 1] : 0) + pref[e][k])) % MOD;
            pr[j] = foo;
            if (j > 0) pr[j] = 1LL * pr[j - 1] * pr[j] % MOD;
        }
        for (int j = (int) g[u].size() - 1; j >= 0; j--) {
            int e = g[u][j];
            int foo = (e == p ? 1 : ((k - i - 1 >= 0 ? pref[e][k - i - 1] : 0) + pref[e][k])) % MOD;
            su[j] = foo;
            if (j + 1 != g[u].size()) su[j] = 1LL * su[j + 1] * su[j] % MOD;
            // cout << j << endl;
        }
        for (int j = 0; j < g[u].size(); j++) {
            int e = g[u][j];
            if (e == p) continue;
            int foo = dp[e][i - 1];
            foo = 1LL * foo * (j == 0 ? 1 : pr[j - 1]) % MOD;
            foo = 1LL * foo * (j + 1 == g[u].size() ? 1 : su[j + 1]) % MOD;
            dp[u][i] = (dp[u][i] + foo) % MOD;
            // cout << j << endl;
        }
        pref[u][i] = (pref[u][i - 1] + dp[u][i]) % MOD;
    }
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    // cout << dp[1][2] << endl;

    cout << pref[1][k] << '\n';

    return 0;
}