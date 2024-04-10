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
    int ans = n + 1;
    for (char c = 'a'; c <= 'z'; ++c) {
      int l = 0, r = n - 1, sum = 0;
      while (l < r) {
        if (s[l] == s[r]) {
          ++l, --r;
          continue;
        }
        if (s[l] == c) {
          ++l;
          ++sum;
        } else if (s[r] == c) {
          --r;
          ++sum;
        } else {
          sum = n + 1;
          break;
        }
      }
      ans = std::min(ans, sum);
    }
    if (ans == n + 1) {
      std::cout << -1 << "\n";
    } else {
      std::cout << ans << "\n";
    }
  }
}