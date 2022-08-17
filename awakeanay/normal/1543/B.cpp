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

    int sum = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      sum += x;
    }

    int k = sum%n;
    std::cout << k*(n-k) << std::endl;
  }

  return 0;
}