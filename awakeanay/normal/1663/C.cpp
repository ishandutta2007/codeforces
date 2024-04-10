#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  int s = 0;
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    s += x;
  }
  std::cout << s << std::endl;

  return 0;
}