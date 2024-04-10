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

    int a[2] = {0, 0};
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[x%2]++;
    }

    std::cout << std::min(a[0], a[1]) << std::endl;
  }

  return 0;
}