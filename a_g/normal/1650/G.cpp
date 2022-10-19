#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+5;
const int INF = 1e9;
vector<int> G[N];
int dist[N], dp[N][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(dist, dist+N, INF);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dist[t] = 0;
    dp[t][0] = 1;
    vector<int> que(1, t);
    for (int i = 0; i < que.size(); i++) {
      int v = que[i];
      for (int u: G[v]) {
        if (dist[u] == dist[v]-1) {
          for (int j = 0; j < 2; j++) {
            dp[v][j] = (dp[v][j] + dp[u][j]) % MOD;
          }
        }
        if (dist[u] == INF) {
          dist[u] = dist[v] + 1;
          que.push_back(u);
        }
      }
      for (int u: G[v]) {
        if (dist[u] == dist[v]) {
          dp[u][1] = (dp[u][1] + dp[v][0]) % MOD;
        }
      }
    }

    cout << (dp[s][0]+dp[s][1]) % MOD << '\n';
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      dist[i] = INF;
      dp[i][0] = 0;
      dp[i][1] = 0;
    }
  }
}