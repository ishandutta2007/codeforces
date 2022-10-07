#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    long long st;
    std::cin >> n >> st;
    std::vector<long long> s(n + 1);
    for (int i = 0; i < n; ++i) {
      int v;
      std::cin >> v;
      s[i + 1] = s[i] + v;
    }

    int ans = 0, ansl = -1;
    std::vector<int> sta;
    for (int i = n; i >= 0; --i) {
      while (!sta.empty() && s[sta.back()] >= s[i]) {
        sta.pop_back();
      }
      sta.push_back(i);
      auto p = std::lower_bound(sta.begin(), sta.end(), s[i] - st,
                                [&](int i, long long v) {
                                  return s[i] < v;
                                });
      int r = p == sta.begin() ? n : *--p - 1;
      if (r - i > ans) {
        ans = r - i;
        ansl = i;
      }
    }
    if (ans == 0) {
      std::cout << -1 << "\n";
    } else {
      std::cout << ansl + 1 << " " << ansl + ans << "\n";
    }
  }
}