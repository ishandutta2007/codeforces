#include <iostream>
#include <map>
#include <vector>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n+1, 0);
    int a[n];
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      if(a[i] <= n)
        p[a[i]] = 1;
    }

    int mx = -1;
    int acc = 0;
    for(int i = 0; i <= n; i++) {
      if(p[i] == 0) {
        if(acc <= k)
          mx = i;
        acc++;
      }
    }

    std::map<int, int> mp;

    for(int i = 0; i < n; i++) {
      if(a[i] > mx) {
        mp[a[i]]++;
      }
    }

    std::set<std::pair<int, int> > st;
    for(auto x : mp) {
      st.insert({x.second, x.first});
    }

    int ans = mp.size();
    while(!st.empty()) {
      auto u = *st.begin();
      st.erase(st.begin());
      if(u.first <= k) {
        k -= u.first;
        ans--;
      }
      else
        break;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}