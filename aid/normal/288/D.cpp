#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 80 * 1000 + 5;
long long ans = 0;
int ts[MAXN], n;
vector<int> g[MAXN];
vector<long long> dp[MAXN][4];

void dfs(int v, int p) {
    ts[v] = 1;
    int gs = g[v].size();
    for(int i = 0; i < gs; i++)
        if(g[v][i] != p) {
            dfs(g[v][i], v);
            ts[v] += ts[g[v][i]];
        }
    for(int i = 0; i < 4; i++)
        dp[v][i].resize(gs);
    for(int i = 0; i < gs; i++)
        if(g[v][i] == p)
            dp[v][0][i] = 0;
        else
            dp[v][0][i] = ts[g[v][i]];
    for(int i = 1; i < gs; i++)
        dp[v][0][i] += dp[v][0][i - 1];
    for(int i = 1; i < 4; i++)
        for(int j = 1; j < gs; j++)
            dp[v][i][j] = dp[v][i][j - 1] +
                (g[v][j] == p? 0 : ts[g[v][j]]) * dp[v][i - 1][j - 1];
    long long d0 = dp[v][0][gs - 1], d1 = dp[v][1][gs - 1],
        d2 = dp[v][2][gs - 1], d3 = dp[v][3][gs - 1];
    ans += d1 * (n - ts[v]) * (n - ts[v]);
    ans += d2 * 6 * (n - ts[v]);
    ans += d3 * 6;
    ans += d0 * (n - ts[v]) * (n - ts[v]);
    ans += (d0 * d0 + 2 * d1) * (n - ts[v]);
    ans += 2 * d1 * (n - ts[v]);
    ans += d1 * d0 + d2 * 3;
    ans += (long long)(n - ts[v]) * (n - ts[v] + 1) / 2;
    ans += d0 * (n - ts[v]) * 2;
    ans += d0 * (d0 + 1) / 2 + d1;
    ans += d2 * d0 - d3 * 4;
    ans += (d1 * d0 - d2 * 3) * (n - ts[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    long long c = (long long)n * (n - 1) / 2;
    ans -= c;
    ans = c * c - ans;
    cout << ans << '\n';
    return 0;
}