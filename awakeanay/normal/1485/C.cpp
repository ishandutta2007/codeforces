#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

int inter(int a, int b, int x, int y) {
  return std::max(0ll, std::min(b, y) - std::max(x, a) + 1);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int x, y;
    std::cin >> x >> y;

    int l = 1, r = x;
    while(l < r) {
      int mid = (l+r)/2;
      if(mid*mid - 1 > x)
        r = mid;
      else
        l = mid+1;
    }

    int same_till = l;
    int ans = 0;
    int p = std::min(same_till-1, y);
    ans += ((p-1)*(p))/2;

    if(same_till > y) {
      std::cout << ans << std::endl;
      continue;
    }

    for(int i = 0; i*i <= x; i++) {
      int start = x/(i+2) + 1;
      int end = x/(i+1);

      ans += inter(start, end, same_till+1, y+1)*(i+1);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}