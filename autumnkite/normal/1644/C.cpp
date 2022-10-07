#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i];
    }
    std::vector<int> ans(n + 1);
    for (int l = 0; l <= n; ++l) {
      for (int r = l; r <= n; ++r) {
        ans[r - l] = std::max(ans[r - l], sum[r] - sum[l] + (r - l) * x);
      }
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = std::max(ans[i], ans[i - 1]);
    }
    for (int k = 0; k <= n; ++k) {
      int min = 0;
      for (int i = k; i <= n; ++i) {
        min = std::min(min, sum[i - k]);
        ans[k] = std::max(ans[k], sum[i] - min + k * x);
      }
    }
    for (int i = 0; i <= n; ++i) {
      std::cout << ans[i] << " \n"[i == n];
    }
  }
}