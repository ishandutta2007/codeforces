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

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i].first;
      a[i].second = i+1;
    }

    std::sort(a, a+n);
    std::cout << a[0].second << " " << a[n-1].second << std::endl;
  }

  return 0;
}