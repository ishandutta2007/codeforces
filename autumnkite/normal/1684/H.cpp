#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::vector<int> min(n + 1), max(n + 1);
    std::vector<std::bitset<256>> mask(n + 1);
    mask[0] = 1;
    for (int i = 0; i < n; ++i) {
      min[i + 1] = min[i] + (s[i] - '0');
      int now = 0;
      for (int j = 0; j <= i && j <= 3; ++j) {
        now += (s[i - j] - '0') << j;
        max[i + 1] = std::max(max[i + 1], max[i - j] + now);
      }
      now = 0;
      for (int j = 0; j <= i && j <= 3; ++j) {
        now += (s[i - j] - '0') << j;
        mask[i + 1] |= mask[i - j] << (max[i + 1] - max[i - j] - now);
      }
    }

    if (min[n] == 0) {
      std::cout << "-1\n";
      continue;
    }

    int val = min[n];
    while (val & (val - 1) || !mask[n][std::min(max[n] - val, 255)]) {
      ++val;
    }

    std::vector<std::pair<int, int>> ans;
    int i = n - 1;
    while (i >= 0) {
      int now = 0;
      for (int j = 0; j <= i && j <= 3; ++j) {
        now += (s[i - j] - '0') << j;
        if (val - now >= min[i - j] && val - now <= max[i - j] &&
            mask[i - j][std::min(max[i - j] - val + now, 255)]) {
          ans.emplace_back(i - j, i);
          i = i - j - 1;
          val -= now;
          break;
        }
      }
    }
    std::reverse(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for (auto [l, r] : ans) {
      std::cout << l + 1 << " " << r + 1 << "\n";
    }
  }
}