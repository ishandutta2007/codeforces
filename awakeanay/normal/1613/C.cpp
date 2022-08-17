#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, h;
    std::cin >> n >> h;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int lo = 1, hi = h;
    while(lo < hi) {
      int mid = (lo+hi)/2;
      int cur = 0;
      bool poss = 0;
      for(int i = 0; i < n; i++) {
        int add = mid;
        if(i+1 < n)
          add = std::min(add, a[i+1]-a[i]);
        cur += add;
        if(cur >= h) {
          poss = 1;
          break;
        }
      }

      if(poss)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}