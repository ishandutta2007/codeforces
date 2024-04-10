#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> s(n + 1);
    for (int i = 0; i < n; ++i) {
      s[i + 1] = a[i] - s[i];
    }

    std::vector<int> sta[2];
    std::map<long long, std::vector<int>> mp[2];

    auto find = [&](int p, long long v) {
      auto it = std::lower_bound(sta[p].begin(), sta[p].end(), v,
                                 [&](int i, long long v) {
                                   return s[i] < v;
                                 });
      if (it == sta[p].begin()) {
        return n;
      } else {
        return *(--it) - 1;
      }
    };

    auto count = [&](int p, long long v, int j) {
      return mp[p][v].end()
             - std::lower_bound(mp[p][v].begin(), mp[p][v].end(), j, 
                                std::greater<int>());
    };

    long long ans = 0;
    for (int i = n; i >= 0; --i) {
      int p = i & 1;
      int j = std::min(find(p, s[i]), find(!p, -s[i]));
      ans += count(p, s[i], j) + count(!p, -s[i], j);
      while (!sta[p].empty() && s[sta[p].back()] >= s[i]) {
        sta[p].pop_back();
      }
      sta[p].push_back(i);
      mp[p][s[i]].push_back(i);
    }
    std::cout << ans << "\n";
  }
}