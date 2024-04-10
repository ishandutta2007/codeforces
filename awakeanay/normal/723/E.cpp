#include <iostream>
#include <set>
#include <vector>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    n++;
    std::set<int> Adj[n];
    std::vector<std::pair<int, int> > sol;

    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[v].insert(u);
      Adj[u].insert(v);
    }

    int ans = 0;
    for(int i = 0; i+1 < n; i++) {
      if(Adj[i].size()%2) {
        Adj[n-1].insert(i);
        Adj[i].insert(n-1);
      }
      else
        ans++;
    }

    std::cout << ans << std::endl;

    int c = 0;
    std::vector<int> vis(n, -1);
    for(int i = 0; i < n; i++) {
      while(!Adj[i].empty()) {
        int cur = i;
        std::vector<int> cycle(1, -1);

        while(vis[cur] != c) {
          vis[cur] = c;
          auto it = Adj[cur].begin();
          if((*it) == cycle.back())
            it++;
          cycle.push_back(cur);
          cur = *it;
        }

        int last = cur;
        while(true) {
          sol.push_back({cycle.back(), last});
          Adj[cycle.back()].erase(last);
          Adj[last].erase(cycle.back());

          if(cycle.back() == cur)
            break;

          last = cycle.back();
          cycle.pop_back();
        }


        c++;
      }
    }

    for(std::pair<int, int> j : sol) {
      if(j.first != n-1 && j.second != n-1) {
        std::cout << j.first+1 << " " << j.second+1 << std::endl;
      }
    }
  }

  return 0;
}