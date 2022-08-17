#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int INF = 10000000000;

signed main() {
  int n, c, d;
  std::cin >> n >> c >> d;

  int max_c = -INF, max_d = -INF;
  std::vector<std::pair<int, int> > best[2];

  for(int i = 0; i < n; i++) {
    int b, p;
    std::cin >> b >> p;
    char t;
    std::cin >> t;

    if(t == 'C') {
      if(p <= c)
        max_c = std::max(max_c, b);
      best[0].push_back({p, b});
    }
    else {
      if(p <= d)
        max_d = std::max(max_d, b);
      best[1].push_back({p, b});
    }
  }

  for(int j = 0; j < 2; j++) {
    std::sort(best[j].begin(), best[j].end());
  }

  int ans = max_c + max_d;
  for(int j = 0; j < 2; j++) {
    int mx = j ? d : c;

    for(int i = 0; i < best[j].size(); i++) {
      if(best[j][i].first > mx)
        continue;

      int nmx = mx - best[j][i].first;
      int idx = std::upper_bound(best[j].begin(), best[j].end(), (std::pair<int, int>){nmx, INF}) - best[j].begin();
      idx = std::min(i-1, idx-1);

      if(idx >= 0) {
        ans = std::max(ans, best[j][i].second + best[j][idx].second);
      }

      if(i)
        best[j][i].second = std::max(best[j][i-1].second, best[j][i].second);
    }
  }

  ans = std::max(ans, 0ll);

  std::cout << ans << std::endl;

  return 0;
}