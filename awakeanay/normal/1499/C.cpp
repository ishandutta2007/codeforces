#include <iostream>

#define int long long

const int INF = 1000000000000000000;

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int c[n];
    int pre[n];
    int ans = INF;
    int sum = 0;
    int min[2];
    min[0] = min[1] = INF;
    int id[2];
    id[0] = id[1] = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> c[i];
      sum += c[i];
      min[i%2] = std::min(min[i%2], c[i]);
      id[i%2]++;
      if(i >= 1) {
        int cur = 0;
        cur += sum;
        cur += (n-id[0])*min[0];
        cur += (n-id[1])*min[1];
        ans = std::min(ans, cur);
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}