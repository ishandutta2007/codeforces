#include <iostream>

#define int long long 
#define INF 100000000000000

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    int l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;

    int ans = INF;
    int init, step;

    int lap = std::min(r1, r2) - std::max(l1, l2);
    if(lap > 0) {
      if(lap*n >= k) {
        std::cout << 0 << std::endl;
        continue;
      }
      k -= lap*n;
      init = 0;
    }
    else {
      init = -lap;
    }

    step = abs(r1-r2) + abs(l2-l1) - init;

    for(int i = 1; i <= n; i++) {
      int req = init*i;
      if(step*i >= k)
        req += k;
      else {
        req += step*i + 2*(k-step*i);
      }
      ans = std::min(ans, req);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}