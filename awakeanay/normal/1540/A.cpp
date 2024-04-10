#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int add = 0;
    int ans = 0;
    int d[n];
    for(int i = 0; i < n; i++) {
      std::cin >> d[i];
      add = std::max(add, d[i]);
    }

    std::sort(d, d+n);

    int sum = d[0];
    for(int i = 1; i < n; i++) {
      ans -= i*d[i]-sum;
      sum += d[i];
    }

    ans += add;
    std::cout << ans << std::endl;
  }

  return 0;
}