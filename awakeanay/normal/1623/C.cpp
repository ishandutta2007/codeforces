#include <iostream>
#include <vector>

#define int long long

const int INF = 1000'000'007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int lo = 0, hi = INF;
    while(lo < hi) {
      int mid = (lo+hi)/2;
      b = a;
      
      bool poss = false;

      for(int i = n-1; i >= 0; i--) {
        if(b[i] < mid)
          poss = true;
        int ex = std::min(b[i]-mid, a[i]);
        int take = ex/3;
        if(i > 1) b[i-1] += take;
        if(i > 1) b[i-2] += 2*take;
      }

      if(poss)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo-1 << std::endl;
  }

  return 0;
}