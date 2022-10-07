#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, x;
    std::cin >> n >> x;
    std::map<long long, int> mp;
    for (int i = 0; i < n; ++i) {
      int v;
      std::cin >> v;
      ++mp[v];
    }
    auto it = mp.begin();
    int ans = 0;
    while (it != mp.end()) {
      int &t = mp[1ll * it->first * x];
      if (t <= it->second) {
        ans += it->second - t;
        mp.erase(1ll * it->first * x);
      } else {
        t -= it->second;
      }
      it = mp.erase(it);
    }
    std::cout << ans << "\n";
  }
}