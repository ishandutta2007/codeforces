#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(26);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    std::string ans(k, 'a');
    int now = k;
    for (int i = 0; i < 26 && i < n / k; ++i) {
      now = std::min(now, cnt[i]);
      for (int j = 0; j < now; ++j) {
        ++ans[j];
      }
    }
    std::cout << ans << "\n";
  }
}