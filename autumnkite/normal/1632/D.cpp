#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::pair<int, int>> f;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<std::pair<int, int>> tmp;
    f.emplace_back(a[i], 1);
    for (auto &[x, c] : f) {
      x = std::gcd(x, a[i]);
      if (tmp.empty() || tmp.back().first != x) {
        tmp.emplace_back(x, c);
      } else {
        tmp.back().second += c;
      }
    }
    f.swap(tmp);
    int k = 0;
    bool ok = true;
    for (auto it = f.rbegin(); it != f.rend(); ++it) {
      auto [x, c] = *it;
      if (k < x && x <= k + c) {
        ok = false;
        break;
      }
      k += c;
    }
    if (!ok) {
      f.clear();
      ++ans;
    }
    std::cout << ans << " \n"[i == n - 1];
  }
}