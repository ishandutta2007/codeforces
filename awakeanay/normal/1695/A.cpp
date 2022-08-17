#include <iostream>

#define int long long

const int INF = 1000'000'009;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int best = -INF;
    int r = -1, c = -1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        int x;
        std::cin >> x;
        if(x > best) {
          best = x;
          r = i;
          c = j;
        }
      }
    }

    int h = std::max(r+1, n-r);
    int w = std::max(c+1, m-c);
    std::cout << h*w << std::endl;
  }

  return 0;
}