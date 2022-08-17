#include <iostream>

#define int long long

const int LOG = 7;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int i = 1;
  std::cout << "? ";
  for(int i = 1; i <= 100; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  int x;
  std::cin >> x;

  x &= (((1 << 7)-1) << 7);
  int ans = x;

  std::cout << "? ";
  for(int i = 1; i <= 100; i++) {
    int cur = i << 7;
    std::cout << cur << " ";
  }
  std::cout << std::endl;

  std::cin >> x;
  ans += x&((1 << 7)-1);

  std::cout << "! " << ans << std::endl;

  return 0;
}