#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int w[N];
vector<int> G[N];
pair<int, int> dp[N][2]; // dp[v][0] = best config if v is not chosen

void dfs(int v, int p) {
  dp[v][1].second = 1-G[v].size();
  dp[v][1].first = 1;
  for (int u: G[v]) {
    if (u != p) {
      dfs(u, v);
      int best = (dp[u][0] > dp[u][1] ? 0 : 1);
      dp[v][0].first += dp[u][best].first;
      dp[v][0].second += dp[u][best].second;
      dp[v][1].first += dp[u][0].first;
      dp[v][1].second += dp[u][0].second;
    }
  }
}

void dfs2(int v, int p, bool b) {
  w[v] = (b ? G[v].size() : 1);
  for (int u: G[v]) {
    if (u != p) {
      if (b) {
        dfs2(u, v, 0);
      }
      else {
        int best = (dp[u][0] > dp[u][1] ? 0 : 1);
        dfs2(u, v, best);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n == 2) {
    cout << "2 2\n1 1\n";
    return 0;
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  bool b = (dp[1][0] > dp[1][1] ? 0 : 1);
  dfs2(1, 1, b);
  pair<int, int> p = dp[1][b];
  cout << p.first << " " << n-p.second << '\n';
  for (int i = 1; i <= n; i++) {
    cout << w[i] << ' ';
  }
  cout << '\n';
}