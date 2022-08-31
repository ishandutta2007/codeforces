#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int w, h;
    std::cin >> w >> h;

    int best = 0;
    for(int i = 0; i < 2; i++) {
      int k;
      std::cin >> k;
      int a[k];
      for(int j = 0; j < k; j++)
        std::cin >> a[j];
      best = std::max(best, h*(a[k-1]-a[0]));
    }

    for(int i = 0; i < 2; i++) {
      int k;
      std::cin >> k;
      int a[k];
      for(int j = 0; j < k; j++)
        std::cin >> a[j];
      best = std::max(best, w*(a[k-1]-a[0]));
    }

    std::cout << best << std::endl;
  }

  return 0;
}