#include <iostream>
#include <algorithm>

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int l[n], r[n];
    std::pair<int, int> points[n];
    for(int i = 0; i < n; i++) {
      std::cin >> l[i] >> r[i];
      points[i] = {l[i], r[i]};
    }

    std::sort(l, l+n);
    std::sort(r, r+n);

    int min = n-1;
    for(int i = 0; i < n; i++) {
      int cur = 0;
      int k = std::upper_bound(l, l+n, points[i].second)-l;
      cur += n-k;
      k = std::lower_bound(r, r+n, points[i].first)-r;
      cur += k;

      min = std::min(min, cur);
    }

    std::cout << min << std::endl;
  }

  return 0;
}