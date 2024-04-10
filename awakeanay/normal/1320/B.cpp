/*
Author: AwakeAnay
Date: 01/03/2020
Time: 18:58:11
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> g[n];
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    g[v].push_back(u);
  }

  std::vector<int> d(n, n+1);

  int k;
  std::cin >> k;
  
  std::vector<int> p(k);
  for(int i = 0; i < k; i++) {
    std::cin >> p[i];
    p[i]--;
  }

  std::queue<int> q;
  q.push(p[k-1]);
  d[p[k-1]] = 0;

  std::set<int> best[n];
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int j : g[u]) {
      if(d[u]+1 < d[j]) {
        d[j] = d[u] + 1;
        q.push(j);
        best[j].insert(u);
      }
      else if(d[u]+1 == d[j])
        best[j].insert(u);
    }
  }

  int min = 0;
  int max = 0;

  int last = 0;
  for(int i = 0; i < k; i++) {
    int x;
    x = p[i];
    if(i) {
      if(best[last].count(x) == 0)
        min++;

      if(best[last].count(x) == 0 || best[last].size() > 1)
        max++;
    }
    last = x;
  }

  std::cout << min << " " << max << std::endl;

  return 0;
}