#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int eq = 0;
    int min = n, max = -1;
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(i && a[i] == a[i-1]) {
        eq++;
        min = std::min(min, i);
        max = std::max(max, i);
      }
    }

    std::cout << std::max(max-min-1, (int)(eq > 1)) << std::endl;
  }

  return 0;
}