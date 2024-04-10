/*
Author: AwakeAnay
Date: 12/02/2020
Time: 14:41:20
*/

#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> d(n, -1);
  std::vector<std::vector<int> > a(n, std::vector<int>(n, 0));
  
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    a[u][v] = a[v][u] = 1;
  }

  std::queue<int> q;
  q.push(0);
  d[0] = 0;

  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = 0; i < n; i++) {
      if(i == u)
        continue;

      if(a[u][i] == a[0][n-1])
        continue;

      if(d[i] == -1) {
        d[i] = d[u] + 1;
        q.push(i);
      }
    }
  }

  std::cout << d[n-1] << std::endl;

  return 0;
}