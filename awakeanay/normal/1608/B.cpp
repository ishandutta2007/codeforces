#include <iostream>
#include <queue>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, a, b;
    std::cin >> n >> a >> b;

    if(a+1 < b || b+1 < a) {
      std::cout << -1 << std::endl;
      continue;
    }

    if(a+b > n-2) {
      std::cout << -1 << std::endl;
      continue;
    }

    int cur;
    if(a > b)
      cur = 1;
    else
      cur = 0;

    std::vector<int> Adj[n];
    std::vector<int> deg(n, 0);
    for(int i = 0; i+1 < n; i++) {
      if(cur) {
        Adj[i].push_back(i+1);
        deg[i+1]++;
      }
      else {
        Adj[i+1].push_back(i);
        deg[i]++;
      }
      if(i < a+b)
        cur ^= 1;
    }

    std::queue<int> bfs;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 0)
        bfs.push(i);
    }

    int val = 1;
    int seq[n];
    while(!bfs.empty()) {
      int u = bfs.front();
      bfs.pop();
      seq[u] = val++;

      for(int j : Adj[u]) {
        deg[j]--;
        if(deg[j] == 0)
          bfs.push(j);
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << seq[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}