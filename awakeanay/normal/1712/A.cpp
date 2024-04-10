#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i].first;
      a[i].second = i;
    }

    std::sort(a, a+n);
    int ans = 0;
    for(int i = k; i < n; i++)
      ans += a[i].second < k;

    std::cout << ans << std::endl;
  }

  return 0;
}