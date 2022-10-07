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
    int l = 0, r = n - 1;
    while (l + 1 < r) {
      ++l, --r;
    }
    while (l > 0 && r + 1 < n && s[l - 1] == s[l] && s[r + 1] == s[r]) {
      --l, ++r;
    }
    std::cout << r - l + 1 << "\n";
  }
}