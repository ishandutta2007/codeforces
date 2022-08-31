#include <iostream>
#include <algorithm>
#include <iomanip>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    for(int i = 1; i < n; i++)
      a[i] += a[i-1];

    long double best = -1000000000000.000;
    for(int i = 0; i+1 < n; i++) {
      long double x = a[i];
      long double y = a[n-1]-x;
      best = std::max(best, x/((long double) (i+1)) + y/((long double)(n-i-1)));
    }

    std::cout << std::fixed << std::setprecision(15) << best << std::endl;
  }

  return 0;
}