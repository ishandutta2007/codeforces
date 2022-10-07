#include <bits/stdc++.h>

template<typename T>
std::vector<int> manacher(const std::vector<T> &a, const std::vector<bool> &ok) {
  int n = a.size();
  std::vector<int> len(n);
  for (int i = 0, l = 0, r = 0; i < n; ++i) {
    if (!ok[i]) {
      continue;
    }
    len[i] = i < r ? std::min(len[2 * l - i], r - i) : 1;
    while (i >= len[i] && i + len[i] < n &&
           ok[i - len[i]] && ok[i + len[i]] &&
           a[i - len[i]] == a[i + len[i]]) {
      ++len[i];
    }
    if (i + len[i] > r) {
      l = i;
      r = i + len[i];
    }
  }
  return len;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    std::vector<std::array<int, 26>> cnt(2 * n + 1);
    std::vector<int> odd(n);
    for (int j = i; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        odd[k] -= cnt[2 * k + 1][a[k][j] - 'a'] & 1;
        ++cnt[2 * k + 1][a[k][j] - 'a'];
        odd[k] += cnt[2 * k + 1][a[k][j] - 'a'] & 1;
      }
      std::vector<bool> ok(2 * n + 1, true);
      for (int i = 0; i < n; ++i) {
        ok[2 * i + 1] = odd[i] <= 1;
      }
      auto len = manacher(cnt, ok);
      for (int i = 0; i < 2 * n + 1; ++i) {
        ans += len[i] / 2;
      }
    }
  }
  std::cout << ans << "\n";
}