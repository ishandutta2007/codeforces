#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int c[MAXN], dp[MAXN][2];
vector<int> g[MAXN];

void dfs(int v) {
    if(c[v])
        dp[v][1] = 1;
    else
        dp[v][0] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        dfs(g[v][i]);
        int ndp1 = ((long long)dp[v][1] * dp[g[v][i]][0]) % MOD;
        ndp1 = (ndp1 + (long long)dp[v][0] * dp[g[v][i]][1]) % MOD;
        int ndp0 = ((long long)dp[v][0] * dp[g[v][i]][0]) % MOD;
        ndp1 = (ndp1 + (long long)dp[v][1] * dp[g[v][i]][1]) % MOD;
        ndp0 = (ndp0 + (long long)dp[v][0] * dp[g[v][i]][1]) % MOD;
        dp[v][0] = ndp0;
        dp[v][1] = ndp1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for(int i = 0; i < n; i++)
        cin >> c[i];
    dfs(0);
    cout << dp[0][1] << '\n';
    return 0;
}