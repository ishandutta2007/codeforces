#include <iostream>
#include <vector>

#define int long long

const int MAXN = 105;
const int MOD = 1000000007;

std::vector<int> Adj[MAXN];
int d[MAXN][MAXN];

void dfs(int u, int p, int h, int dep) {
  d[h][dep]++;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, h, dep+1);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  int binom[MAXN][MAXN];
  for(int i = 0; i < MAXN; i++)
    binom[i][0] = binom[i][i] = 1;
  for(int j = 2; j < MAXN; j++)
    for(int k = 1; k < j; k++) {
      binom[j][k] = (binom[j-1][k-1] + binom[j-1][k])%MOD;
    }

  while(t--) {
    int n, k;
    std::cin >> n >> k;


    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        d[i][j] = 0;
      Adj[i].clear();
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    if(k == 2) {
      std::cout << ((n*(n-1))/2)%MOD << std::endl;
      continue;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(Adj[i].size() < k)
        continue;

      for(int j : Adj[i]) {
        for(int p = 0; p < n; p++)
          d[j][p] = 0;
        dfs(j, i, j, 0);
      }

      for(int j = 0; j < n; j++) {
        int cur[k+1] = {0};
        cur[0] = 1;

        for(int p : Adj[i]) {
          for(int q = k; q > 0; q--) {
            cur[q] = (cur[q-1]*d[p][j] + cur[q])%MOD;
          }
        }

        ans = (ans + cur[k])%MOD;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}