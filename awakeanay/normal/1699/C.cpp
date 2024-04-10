#include <iostream>

#define int long long

const int MOD = 1000'000'007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int rev[n];
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      rev[x] = i;
    }

    int l = rev[0], r = rev[0];
    int ans = 1;
    for(int i = 1; i < n; i++) {
      int nl = std::min(l, rev[i]);
      int nr = std::max(r, rev[i]);

      if(nl == l && nr == r) {
        ans = (ans*(r-l+1-i))%MOD;
      }

      l = nl;
      r = nr;
    }
    
    std::cout << ans << "\n";
  }

  return 0;
}