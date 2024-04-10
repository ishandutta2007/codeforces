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

    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;

      if(x == 1)
        a = i;
      else if(x == n)
        b = i;
    }

    if(a < b)
      a ^= b ^= a ^= b;
    int ans = std::min(a+1, n-b);
    ans = std::min(ans, n-a + b+1);
    std::cout << ans << std::endl;
  }

  return 0;
}