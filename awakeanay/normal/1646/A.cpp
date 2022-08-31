#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, s;
    std::cin >> n >> s;
    n *= n;
    std::cout << s/n << std::endl;
  }

  return 0;
}