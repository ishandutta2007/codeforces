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

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      ans ^= (x-1);
    }

    std::cout << (ans%2 == 0 ? "maomao90" : "errorgorn") << std::endl;
  }

  return 0;
}