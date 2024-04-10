#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int cur = 0;
    for(int i = 0; i < m; i++) {
      int x;
      std::cin >> x >> x >> x;
      cur |= x;
    }

    int p2 = 1;
    for(int i = 1; i < n; i++)
      p2 = (p2*2)%MOD;

    int ans = 0;
    for(int i = 31; i >= 0; i--) {
      if((cur >> i)&1)
        ans = (ans + p2*(1 << i))%MOD;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}