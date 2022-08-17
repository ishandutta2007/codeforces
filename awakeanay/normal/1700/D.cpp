#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int v[n];
  int sum = 0;
  int min = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> v[i];
    sum += v[i];
    min = std::max(min, (sum/(i+1)) + ((sum%(i+1)) != 0));
  }

  int q;
  std::cin >> q;

  while(q--) {
    int t;
    std::cin >> t;

    if(t < min) {
      std::cout << -1 << std::endl;
    }
    else {
      int lo = 1, hi = n;
      while(lo < hi) {
        int mid = (lo+hi)/2;
        if(mid*t >= sum)
          hi = mid;
        else
          lo = mid+1;
      }
      std::cout << lo << std::endl;
    }
  }

  return 0;
}