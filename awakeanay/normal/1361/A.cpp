#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> Adj[n];
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  std::pair<int, int> arr[n];
  int seq[n];
  for(int i = 0; i < n; i++) {
    std::cin >> arr[i].first;
    seq[i] = arr[i].first;
    arr[i].second = i+1;
  }

  std::sort(arr, arr+n);

  bool poss = true;
  std::vector<int> vis(n, 0);
  for(int i = 0; i < n; i++) {
    int u = arr[i].second-1;
    std::set<int> s;
    int c = 0;
    for(int j : Adj[u]) {
      if(vis[j] && !s.count(seq[j])) {
        if(seq[j] == seq[u]) {
          poss = false;
        }
        s.insert(seq[j]);
        c++;
      }
    }

    if(c != seq[u]-1) {
      poss = false;
      break;
    }
    else
      vis[u] = true;
  }

  if(poss) {
    for(int j = 0; j < n; j++)
      std::cout << arr[j].second << " ";
  }
  else
    std::cout << -1;

  std::cout << std::endl;
  return 0;
}