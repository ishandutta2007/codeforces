#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    std::vector<bool> vis(26);
    for (int i = 0; i < k; ++i) {
      char c;
      std::cin >> c;
      vis[c - 'a'] = true;
    }
    int ans = 0;
    int lst = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[s[i] - 'a']) {
        ans = std::max(ans, i - lst);
        lst = i;
      }
    }
    std::cout << ans << "\n";
  }
}