#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
long long dp[N], dp2[N];
int s[N];

void dfs(int v, int k) {
  dp[v] = 1LL*k*s[v];
  dp2[v] = s[v];
  int c = (int)G[v].size();
  if (c == 0) return;
  for (int u: G[v]) {
    dfs(u, k/c);
    dp[v] += dp[u];
  }
  sort(G[v].begin(), G[v].end(), [&] (int x, int y) {
    return dp2[x] > dp2[y];
      });
  for (int i = 0; i < k%c; i++) {
    dp[v] += dp2[G[v][i]];
  }
  dp2[v] += dp2[G[v][k%c]];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      G[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    dfs(1, k);
    cout << dp[1] << '\n';
  
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}