#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> mp;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      mp[x]++;
    }

    std::set<int> sizes;
    std::vector<int> sz[n+1];
    int val[n];
    int ct = 0;
    for(auto j : mp) {
      val[ct++] = j.first;
      sz[j.second].push_back(j.first);
      sizes.insert(j.second);
    }

    for(int i = 1; i <= n; i++)
      std::sort(sz[i].rbegin(), sz[i].rend());

    std::set<std::pair<int, int> > st;
    for(int i = 0; i < m; i++) {
      int x, y;
      std::cin >> x >> y;
      st.insert({x, y});
      st.insert({y, x});
    }

    int best = 0;
    for(int i = 0; i < ct; i++) {
      int s1 = mp[val[i]];
      for(int j : sizes) {
        int y = 0;

        for(int k = 0; k < sz[j].size(); k++) {
          if((!st.count({val[i], sz[j][k]})) && (val[i] != sz[j][k])) {
            y = sz[j][k];
            break;
          }
        }

        if(y) {
          best = std::max(best, (j+s1)*(val[i] + y));
        }
      }
    }

    std::cout << best << std::endl;
  }

  return 0;
}