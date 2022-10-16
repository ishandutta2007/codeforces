#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int dp[MAXN][2], l[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    l[v] = g[v].empty();
    for(size_t i = 0; i < g[v].size(); i++) {
        dfs(g[v][i]);
        l[v] += l[g[v][i]];
    }
    for(size_t i = 0; i < g[v].size(); i++) {
        dp[v][0] = max(dp[v][0], l[v] - (l[g[v][i]] - dp[g[v][i]][1]));
        dp[v][1] += dp[g[v][i]][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
    }
    dfs(0);
    cout << dp[0][0] + 1 << ' ' << l[0] - dp[0][1] << '\n';
    return 0;
}