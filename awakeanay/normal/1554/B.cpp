#include <iostream>

#define int long long

const int INF = 100000000000000;
const int MAX = 300;

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

    int max = -INF;
    for(int i = 0; i < std::min(n, MAX); i++) {
      int cur = n-1-i;
      for(int j = 0; j < cur; j++) {
        max = std::max(max, (cur+1)*(j+1)-k*(a[cur]|a[j]));
      }
    }

    std::cout << max << std::endl;
  }

  return 0;
}