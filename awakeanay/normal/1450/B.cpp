#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::pair<int, int> p[n];
    for(int i = 0; i < n; i++)
      std::cin >> p[i].first >> p[i].second;

    bool poss = false;
    for(int i = 0; i < n; i++) {
      int c = 0;
      for(int j = 0; j < n; j++) {
        if(abs(p[j].first-p[i].first) + abs(p[j].second-p[i].second) <= k) {
          c++;
        }
      }
      if(c == n)
        poss = true;
    }

    if(poss)
      std::cout << 1 << std::endl;
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}