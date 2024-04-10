/*
Author: AwakeAnay
Date: 17/02/2020
Time: 21:39:47
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> sp(k);
  for(int i = 0; i < k; i++) {
    std::cin >> sp[i];
    sp[i]--;
  }

  std::vector<int> Adj[n];
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  
  std::vector<int> d1(n, n), dn(n, n);
  d1[0] = 0; dn[n-1] = 0;
  
  std::queue<int> q;
  q.push(0);

  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int j : Adj[u]) {
      if(d1[j] > d1[u] + 1) {
        d1[j] = d1[u]+1;
        q.push(j);
      }
    }
  }
  
  q.push(n-1);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int j : Adj[u]) {
      if(dn[j] > dn[u] + 1) {
        dn[j] = dn[u]+1;
        q.push(j);
      }
    }
  }
  int ans = d1[n-1];
  std::vector<std::pair<int, int> > help;
  for(int j : sp) {
    help.push_back({d1[j], j});
  }

  std::sort(help.begin(), help.end());

  int max = dn[help[k-1].second];
  int max2 = 0;
  for(int j = k-2; j >= 0; j--) {
    max2 = std::max(max2, max+d1[help[j].second]+1);
    max = std::max(max, dn[help[j].second]);
  }

  ans = std::min(ans, max2);
  std::cout << ans << std::endl;
  return 0;
}