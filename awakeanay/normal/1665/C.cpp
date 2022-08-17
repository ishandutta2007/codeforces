#include <iostream>
#include <vector>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> deg(n, 0);
    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      deg[x]++;
    }

    std::set<std::pair<int, int> > a, b;
    a.insert({1, -1});
    
    for(int j = 0; j < n; j++) {
      if(deg[j])
        a.insert({deg[j], j});
    }

    for(int i = 1; i <= n+1; i++) {
      bool ad = a.empty();
      bool bd = b.empty() || ((*b.rbegin()).first <= i-1);

      if(ad && bd) {
        std::cout << i-1 << std::endl;
        break;
      }

      if(!a.empty()) {
        auto u = *a.rbegin();
        b.insert({u.first + i-1, u.second});
        a.erase(u);
      }
      else {
        auto u = *b.rbegin();
        b.insert({u.first-1, u.second});
        b.erase(u);
      }
    }
  }

  return 0;
}