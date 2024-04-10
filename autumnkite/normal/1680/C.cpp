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
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      tot += s[i] - '0';
    }
    int c[2] = {};
    int ans = tot;
    for (int i = 0; i < n; ++i) {
      ++c[s[i] - '0'];
      if (i >= tot) {
        --c[s[i - tot] - '0'];
      }
      ans = std::min(ans, std::max(c[0], tot - c[1]));
    }
    std::cout << ans << "\n";
  }
}