#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::pair<int, int> max = {-1, -1};
    int min = -1;

    for(int i = 0; i < n; i++) {
      int val = 0;
      for(int j = 0; j < m; j++) {
        int c;
        std::cin >> c;
        val += c*(j+1);
      }
      max = std::max(max, {val, i});
      if(i == 0)
        min = val;
      else
        min = std::min(min, val);
    }

    std::cout << max.second+1 << " " << max.first-min << std::endl;
  }

  return 0;
}