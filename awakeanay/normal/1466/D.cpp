#include <iostream>
#include <set>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int w[n];
    for(int i = 0; i < n; i++)
      std::cin >> w[i];

    std::vector<int> deg(n, 0);
    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      deg[u]++; deg[v]++;
    }

    int cans = 0;
    std::set<std::pair<int, int> > vert;
    for(int i = 0; i < n; i++) {
      cans += deg[i]*w[i];
      if(deg[i] > 1) vert.insert({w[i], i});
    }

    int ans[n];
    for(int i = n-1; i >= 1; i--) {
      ans[i] = cans;
      if(!vert.empty()) {
        std::pair<int, int> next = *vert.begin();
        vert.erase(vert.begin());
        cans -= next.first;
        deg[next.second]--;
        if(deg[next.second] > 1)
          vert.insert(next);
      }
    }

    for(int i = 1; i < n; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}