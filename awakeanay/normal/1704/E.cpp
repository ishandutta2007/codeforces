#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int MOD = 998244353;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> Adj[n];

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int deg[n] = {0};
    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      deg[v]++;
      Adj[u].push_back(v);
    }

    int cur = -1;
    for(int i = 0; i <= n+1; i++) {
      int na[n];
      int sum = 0;
      for(int i = 0; i < n; i++) {
        na[i] = a[i];
        sum += a[i];
      }
      if(sum == 0) {
        cur = i;
        break;
      }
      for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
          na[i]--;
          for(int j : Adj[i])
            na[j]++;
        }
      }
      for(int i = 0; i < n; i++) {
        a[i] = na[i];
      }
    }

    if(cur != -1) {
      std::cout << cur << std::endl;
      continue;
    }
    cur = n+2;

    int dp[n] = {0};
    std::queue<int> topo;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 0) {
        topo.push(i);
      }
    }

    while(!topo.empty()) {
      int u = topo.front();
      topo.pop();

      dp[u] = (dp[u] + a[u])%MOD;
      for(int j : Adj[u]) {
        dp[j] = (dp[j] + dp[u])%MOD;
        deg[j]--;
        if(deg[j] == 0) {
          topo.push(j);
        }
      }
    }

    int ans = -1;
    for(int i = 0; i < n; i++) {
      if(Adj[i].size() == 0)
        ans = dp[i];
    }

    std::cout << (ans+cur)%MOD << std::endl;
  }

  return 0;
}