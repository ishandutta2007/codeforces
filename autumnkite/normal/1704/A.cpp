#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    bool ok = true;
    for (int i = 0; i < m - 1; ++i) {
      ok &= a[i] == b[i];
    }
    if (!ok) {
      std::cout << "NO\n";
      continue;
    }
    ok = false;
    for (int i = m - 1; i < n; ++i) {
      ok |= a[i] == b[m - 1];
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}