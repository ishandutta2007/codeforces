#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int cnt[2] = {};
    for (char c : s) {
      ++cnt[c - '0'];
    }
    std::cout << std::min(cnt[0], cnt[1]) - (cnt[0] == cnt[1]) << "\n";
  }
}