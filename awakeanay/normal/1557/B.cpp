#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::pair<int, int> help[n];
    for(int i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
    }

    std::sort(help, help+n);

    int min = 1;
    for(int i = 1; i < n; i++) {
      if(help[i-1].second + 1 != help[i].second)
        min++;
    }

    std::cout << ((min <= k) ? "Yes" : "No") << std::endl;
  }

  return 0;
}