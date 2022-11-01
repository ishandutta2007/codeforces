#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

vector <int> g[N];
int n, sub[N], dp[N];

void dfs (int u = 1, int par = 1) {
    sub[u] = 1;
    for (int v : g[u]) if (v != par) {
        dfs(v, u);
        sub[u] += sub[v];
    }
}

void bfs (void) {
    memset(dp, -1, sizeof dp);
    queue <int> q; q.push(1);
    dp[1] = 2;
    while (not q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dp[v] == -1) {
            dp[v] = dp[u] + sub[u] - sub[v] + 1;
            q.push(v);
        }
    }
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for (int u = 2, v; u <= n; ++u) {
        scanf("%d", &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(); bfs();

    for (int i = 1; i <= n; ++i)
        printf("%0.1f ", (double) dp[i]/2.0);

    puts("");
    return 0;
}