#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int dp[MAXN], ans[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    dp[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        dfs(g[v][i]);
        dp[v] = (long long)dp[v] * (dp[g[v][i]] + 1) % MOD;
    }
}

void dfs0(int v, int x) {
    ans[v] = (long long)dp[v] * (x + 1) % MOD;
    int m = g[v].size();
    vector<int> pref(m + 1), suf(m + 1);
    pref[0] = (x + 1) % MOD;
    for(int i = 0; i < m; i++)
        pref[i + 1] = (long long)pref[i] * (dp[g[v][i]] + 1) % MOD;
    suf[m] = 1;
    for(int i = m - 1; i >= 0; i--)
        suf[i] = (long long)suf[i + 1] * (dp[g[v][i]] + 1) % MOD;
    for(int i = 0; i < m; i++)
        dfs0(g[v][i], (long long)pref[i] * suf[i + 1] % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs(0);
    dfs0(0, 0);
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}