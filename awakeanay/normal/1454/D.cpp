#include <iostream>
#include <vector>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > ps;
    int max = 1;
    for(int i = 2; i*i <= n; i++) {
      if(n%i == 0) {
        int c = 0;
        while(n%i == 0) {
          n /= i;
          c++;
        }
        ps.push_back({i, c});
        max = std::max(c, max);
      }
    }

    if(n != 1) {
      ps.push_back({n, 1});
    }

    std::vector<int> ans(max, 1);
    for(int i = 0; i < ps.size(); i++) {
      for(int j = 0; j < ps[i].second; j++) {
        ans[max-1-j] *= ps[i].first;
      }
    }

    std::cout << max << std::endl;
    for(int i = 0; i < max; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}