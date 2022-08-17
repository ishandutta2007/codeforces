#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > a;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a.push_back({x, 1});
    }

    int ans = -1;
    while(true) {
      if(a.size() == 1 && a.front().second == 1) {
        ans = a.front().first;
        break;
      }

      int m = a.size();
      std::vector<std::pair<int, int> > next;
      int last = -1;
      for(int i = 0; i < m; i++) {
        if(a[i].second > 1) {
          next.push_back({0, a[i].second-1});
        }
        if(last != -1)
          next.push_back({a[i].first-last, 1});
        last = a[i].first;
      }

      std::vector<std::pair<int, int> > red;
      std::sort(next.begin(), next.end());
      for(int i = 0; i < next.size(); i++) {
        int j = i;
        int cur = 0;
        while(j < next.size() && next[j].first == next[i].first) {
          cur += next[j].second;
          j++;
        }
        red.push_back({next[i].first, cur});
        i = j-1;
      }

      a = red;
    }

    std::cout << ans << "\n";
  }

  return 0;
}