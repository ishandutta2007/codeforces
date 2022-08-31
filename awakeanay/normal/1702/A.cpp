#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int m;
    std::cin >> m;

    int ct = 1;
    int nm = m;
    while(nm > 0) {
      nm /= 10;
      ct *= 10;
    }

    ct /= 10;
    std::cout << (m-ct) << std::endl;
  }

  return 0;
}