#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> open(n, 0);
    std::vector<int> close(n, 0);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      int k = std::max(i-x+1, 0ll);
      if(k < n) open[k]++;
      close[i]++;
    }

    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += open[i];
      std::cout << (cur > 0) << " ";
      cur -= close[i];
    }

    std::cout << std::endl;
  }

  return 0;
}