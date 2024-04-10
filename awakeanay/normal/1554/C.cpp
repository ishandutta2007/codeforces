#include <iostream>

#define int long long

const int LOGN = 35;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int ans = (1ll << 33);
    for(int i = 0; i < LOGN; i++) {
      if((m >> i)&1ll)
        continue;

      int new_n = n - n%(1ll << (i+1));
      int new_m = m - m%(1ll << (i+1));

      ans = std::min(ans, (new_n^new_m) + (1ll << i)*(((n >> i)&1ll) == 0));
    }

    std::cout << ans << std::endl;
  }

  return 0;
}