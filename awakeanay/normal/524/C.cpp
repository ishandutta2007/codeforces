#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXA = 200'000'007;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int> > dp;
  int a[n];

  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    int xy = a[i];

    for(int j = 1; j <= k; j++) {
      if(xy >= MAXA)
        break;
      dp.push_back({xy, j});
      xy += a[i];
    }
  }

  dp.push_back({0, 0});

  std::sort(dp.begin(), dp.end());

  int q;
  std::cin >> q;

  while(q--) {
    int x;
    std::cin >> x;

    int ans = k+1;
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= k; j++) {
        int cur = a[i]*j;
        int rem = x-cur;
        std::pair<int, int> comp = {rem, -1};
        auto it = std::lower_bound(dp.begin(), dp.end(), comp);

        if(it == dp.end())
          continue;

        if((*it).first != rem)
          continue;

        ans = std::min(ans, j+(*it).second);
      }
    }

    std::cout << (ans == k+1 ? -1 : ans) << std::endl;
  }

  return 0;
}