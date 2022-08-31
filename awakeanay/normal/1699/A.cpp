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

    if(n&1) {
      std::cout << -1 << "\n";
    }
    else {
      std::cout << (n >> 1) << " " << 0 << " " << 0 << "\n";
    }
  }

  return 0;
}