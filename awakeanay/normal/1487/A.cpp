#include <iostream>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    int min = 101;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      min = std::min(a[i], min);
    }

    int ans = n;
    for(int i = 0; i < n; i++)
      ans -= a[i] == min;

    std::cout << ans << std::endl;
  }

  return 0;
}