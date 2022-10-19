#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
int dp[N], indeg[N], inold[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    indeg[v]++;
  }
  vector<int> que;
  for (int i = 1; i <= n; i++) {
    inold[i] = indeg[i];
    dp[i] = 1;
    if (indeg[i] == 0) {
      que.push_back(i);
    }
  }

  for (int i = 0; i < que.size(); i++) {
    int v = que[i];
    for (int u: G[v]) {
      indeg[u]--;
      if (!indeg[u]) {
        que.push_back(u);
      }
      if (G[v].size() > 1 && inold[u] > 1) {
        dp[u] = max(dp[u], dp[v]+1);
      }
    }
  }

  cout << *max_element(dp+1, dp+n+1) << '\n';
}