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
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= s[i] == s[n - i - 1];
    }
    std::cout << (ok || k == 0 ? 1 : 2) << "\n";
  }
}