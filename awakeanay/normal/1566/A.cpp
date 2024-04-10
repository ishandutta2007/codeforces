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

    int min = n/2+1;
    std::cout << s/min << std::endl;
  }

  return 0;
}