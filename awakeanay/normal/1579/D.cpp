#include <iostream>
#include <vector>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::set<std::pair<int, int> > s;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if(x != 0)
        s.insert({-x, i+1});
    }

    std::vector<std::pair<int, int> > ans;
    while(s.size() > 1) {
      auto u = *s.begin();
      s.erase(s.begin());
      auto v = *s.begin();
      s.erase(s.begin());

      ans.push_back({u.second, v.second});
      u.first++;
      v.first++;
      if(u.first != 0)
        s.insert(u);
      if(v.first != 0)
        s.insert(v);
    }

    std::cout << ans.size() << std::endl;
    for(auto j : ans)
      std::cout << j.first << " " << j.second << std::endl;
  }

  return 0;
}