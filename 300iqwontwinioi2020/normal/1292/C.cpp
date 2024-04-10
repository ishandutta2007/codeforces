#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector < int > g[3006];

int P[3005][3005];
int D[3005][3005];
int S[3005][3005];
int dp[3005][3005];

void dfs (int k, int p, int s){
    P[s][k] = p;
    S[s][k] = 1;
    D[s][k] = D[s][p] + 1;
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k, s);
        S[s][k] += S[s][to];
    }
}

vector < pair < int, int > > V[3005];

main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    for (int i = 1; i <= n; i++)
        dfs (i, 0, i);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            V[D[i][j]].push_back ({i, j});
    int ans = 0;
    for (int I = 1; I <= n; I++)
        for (auto X : V[I]){
            int u = X.first, v = X.second;
            int a = P[v][u], b = P[u][v];
            int c = max (dp[u][b], dp[v][a]);
            dp[u][v] = c + S[u][v] * S[v][u];
            dp[v][u] = dp[u][v];
            ans = max (ans, dp[u][v]);
        }
    cout << ans << endl;
}