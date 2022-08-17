#include <iostream>
#include <vector>
#include <queue>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  int n;
  std::cin >> n;

  std::vector<int> Adj[n];
  std::vector<int> deg(n, 0);
  int p[n];
  p[0] = -1;

  for(int i = 1; i < n; i++) {
    int x;
    std::cin >> x;
    p[i] = x-1;
    Adj[x-1].push_back(i);
    deg[x-1]++;
  }

  int ans = 0;

  std::queue<int> bfs;
  for(int i = 0; i < n; i++) {
    if(deg[i] == 0)
      bfs.push(i);
  }

  int given[n];
  for(int i = 0; i < n; i++)
    std::cin >> given[i];

  bool poss = true;

  while(!bfs.empty()) {
    int u = bfs.front();
    bfs.pop();

    if(given[u] == -1) {
      for(int j : Adj[u]) {
        if(given[u] == -1)
          given[u] = given[j];
        else
          given[u] = std::min(given[u], given[j]);
      }
    }

    for(int j : Adj[u]) {
      if(given[j] != -1 && given[j] < given[u]) {
        poss = false;
        break;
      }
      else if(given[j] != -1) {
        ans += given[j]-given[u];
      }
    }

    if(u == 0) {
      ans += given[0];
      break;
    }

    deg[p[u]]--;
    if(deg[p[u]] == 0)
      bfs.push(p[u]);
  }

  std::cout << (poss ? ans : -1) << std::endl;

  return 0;
}