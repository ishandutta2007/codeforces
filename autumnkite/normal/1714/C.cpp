#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int s;
    std::cin >> s;
    std::string ans;
    for (int i = 9; i >= 1; --i) {
      if (s >= i) {
        s -= i;
        ans.push_back('0' + i);
      }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << "\n";
  }
}