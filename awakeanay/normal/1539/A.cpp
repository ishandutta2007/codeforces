#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k;
  std::cin >> k;

  while(k--) {
    int n, x, t;
    std::cin >> n >> x >> t;

    int last = t/x;
    int rem = n-(last+1);
    int first = std::min(last+1, n);
    int ans = (first*(first-1))/2;
    if(rem > 0)
      ans += rem*last;

    std::cout << ans << std::endl;
  }

  return 0;
}