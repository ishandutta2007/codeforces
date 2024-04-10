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
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += s[i] == '1';
    }
    std::vector<int> pos;
    for (int i = 0; i < n; ++i) {
      if ((s[i] == '1') ^ (i >= n - cnt)) {
        pos.push_back(i);
      }
    }
    if (pos.empty()) {
      std::cout << 0 << "\n";
    } else {
      std::cout << 1 << "\n";
      std::cout << pos.size();
      for (int x : pos) {
        std::cout << " " << x + 1;
      }
      std::cout << "\n";
    }
  }
}