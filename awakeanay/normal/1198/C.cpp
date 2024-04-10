#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;
    n *= 3;

    std::vector<int> mark(n, 0);
    std::vector<int> edges;

    int k = n/3;

    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      if((!mark[u]) && (!mark[v])) {
        edges.push_back(i+1);
        mark[u] = mark[v] = 1;
      }
    }

    if(edges.size() >= k) {
      std::cout << "Matching" << std::endl;
      int cur = 0;
      for(int j : edges) {
        std::cout << j << " ";
        cur++;
        if(cur == k)
          break;
      }
      std::cout << std::endl;
    }
    else {
      std::cout << "IndSet" << std::endl;
      int c = 0;
      for(int i = 0; i < n; i++) {
        if(!mark[i]) {
          std::cout << i+1 << " ";
          c++;
          if(c == k)
            break;
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}