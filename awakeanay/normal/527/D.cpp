#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int> > val;

  for(int i = 1; i <= n; i++) {
    int x, w;
    std::cin >> x >> w;

    val.push_back({x-w, i});
    val.push_back({x+w, -i});
  }

  std::sort(val.begin(), val.end());

  int ans = 0;
  std::set<int> poss;

  for(auto j : val) {
    if(j.second > 0) {
      poss.insert(j.second);
    }
    else {
      int u = -j.second;
      if(poss.count(u)) {
        ans++;
        poss.clear();
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}