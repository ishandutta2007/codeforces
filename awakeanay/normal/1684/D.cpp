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

    int a[n];
    int tot = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      tot += a[i];
      a[i] -= n-1-i;
    }

    std::sort(a, a+n);
    std::reverse(a, a+n);

    for(int i = 0; i < k; i++)
      tot -= a[i];

    tot -= (k*(k-1))/2;
    std::cout << tot << std::endl;
  }

  return 0;
}