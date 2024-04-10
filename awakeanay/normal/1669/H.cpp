#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int bit[31] = {0};
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      for(int j = 0; j < 31; j++)
        bit[j] += (x >> j)&1;
    }

    int ans = 0;
    for(int j = 30; j >= 0; j--) {
      int need = n-bit[j];
      if(need <= k) {
        k -= need;
        ans |= 1 << j;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}