#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int INF = 1'000'000'000'000;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int k[n], h[n];

    std::vector<std::pair<int, int> > calc;

    for(int i = 0; i < n; i++)
      std::cin >> k[i];
    for(int i = 0; i < n; i++)
      std::cin >> h[i];

    for(int i = 0; i < n; i++) {
      calc.push_back({k[i], 1});
      calc.push_back({k[i]-h[i]+1, 0});
    }

    int cur = 0;
    int last = -1;
    std::sort(calc.begin(), calc.end());
    int ans = 0;

    for(auto j : calc) {
      if(j.second == 0) {
        if(cur == 0)
          last = j.first;
        cur++;
      }
      else {
        cur--;
        if(cur == 0) {
          int num = j.first-last+1;
          ans += (num*(num+1))/2;
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}