#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, l, r, k;
    std::cin >> n >> l >> r >> k;

    std::vector<int> ch;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(l <= x && x <= r)
        ch.push_back(x);
    }

    std::sort(ch.begin(), ch.end());

    int ans = 0;
    for(int j : ch) {
      if(j <= k) {
        ans++;
        k -= j;
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}