#include <iostream>

#define int long long
#define INF 1000000000000

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int max = (1 << 9);
    int ans = INF;
    for(int i = 1; i < max; i++) {
      int sum = 0;
      int number = 0;
      for(int j = 0; j < 9; j++) {
        if((i >> j)&1) {
          sum += j+1;
          number *= 10;
          number += j+1;
        }

        if(sum == n) {
          ans = std::min(number, ans);
        }
      }
    }

    if(ans < INF)
      std::cout << ans << std::endl;
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}