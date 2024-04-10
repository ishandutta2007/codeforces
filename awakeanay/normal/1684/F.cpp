#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int a[n];
    std::map<int, int> mp;
    int ct = 0;
    std::vector<int> pos[n];
    int lim[2][n];

    std::vector<int> best(n, -1);
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
      int l, r;
      std::cin >> l >> r;
      l--; r--;
      best[l] = std::max(best[l], r);
    }

    int ctn = 0;
    for(int i = 0; i < n; i++) {
      lim[0][i] = lim[1][i] = -1;
      if(i)
        best[i] = std::max(best[i], best[i-1]);
      if(mp.find(a[i]) == mp.end()) {
        mp[a[i]] = ct++;
      }
      int u = mp[a[i]];
      pos[u].push_back(i);
      int k = pos[u].size();

      if(k > 1) {
        int lo = 0, hi = k-1;
        while(lo < hi) {
          int mid = (lo+hi)/2;
          if(best[pos[u][mid]] >= i)
            hi = mid;
          else
            lo = mid+1;
        }

        if(lo != k-1) {
          lim[0][i] = lo;
          lim[1][i] = k-1;
        }
      }
    }


    std::set<std::pair<int, int> > st;
    std::vector<int> ch[n];
    int till = 0;

    for(int i = 0; i < n; i++) {
      if(lim[0][i] == -1)
        continue;

      int u = mp[a[i]];
      st.insert({pos[u][lim[0][i]+1], i});
      ch[pos[u][lim[1][i]]].push_back(i);
      till = std::max(till, pos[u][lim[1][i]-1]);
    }

    int ans = n;
    for(int i = n-1; i >= till; i--) {
      if(st.empty()) {
        ans = 0;
      }
      else {
        auto u = *st.begin();
        ans = std::min(ans, i-u.first+1);
      }

      for(int j : ch[i]) {
        int u = mp[a[j]];
        st.insert({pos[u][lim[0][j]], j});
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}