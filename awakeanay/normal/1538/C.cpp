#include <iostream>
#include <algorithm>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, l, r;
    std::cin >> n >> l >> r;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    int lo = n-1;
    int hi = n-1;
    int ans = 0;
    for(int i = 1; i < n; i++) {
      while(lo >= 0 && a[lo] + a[i] >= l)
        lo--;
      lo++;
      if(a[lo]+a[i] < l)
        lo = n;
      while(hi >= 0 && a[i]+a[hi] > r)
        hi--;
      ans += std::max(0ll, std::min(hi, i-1)-lo+1);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}