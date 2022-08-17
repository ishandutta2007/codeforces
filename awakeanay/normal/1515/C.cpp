#include <iostream>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m, x;
    std::cin >> n >> m >> x;

    std::set<std::pair<int, int> > best;
    int val[m];

    for(int i = 0; i < m; i++) {
      val[i] = 0;
      best.insert({0, i});
    }

    std::cout << "YES" << std::endl;
    for(int i = 0; i < n; i++) {
      int y;
      std::cin >> y;
      int cur = (*best.begin()).second;
      best.erase({val[cur], cur});
      val[cur] += y;
      std::cout << cur+1 << " ";
      best.insert({val[cur], cur});
    }
    std::cout << std::endl;
  }

  return 0;
}