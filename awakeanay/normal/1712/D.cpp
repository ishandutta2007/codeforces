#include <iostream>

#define int long long

const int INF = 1000'000'000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int lo = 1, hi = INF+1;
    while(lo < hi) {
      int mid = (lo+hi)/2;

      int b[n];
      int need = 0;
      for(int i = 0; i < n; i++) {
        b[i] = a[i];
        if(2*b[i] < mid) {
          b[i] = INF;
          need++;
        }
      }

      int add = 2;
      for(int i = 0; i+1 < n; i++) {
        if(std::min(b[i], b[i+1]) >= mid)
          add = 0;
        if(std::min(b[i], b[i+1]) < mid && std::max(b[i], b[i+1]) >= mid)
          add = std::min(add, 1ll);
      }

      if(need + add <= k)
        lo = mid+1;
      else
        hi = mid;
    }

    std::cout << lo-1 << "\n";
  }

  return 0;
}