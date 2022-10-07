#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long hc, dc, hm, dm, h, d;
    int n;
    std::cin >> hc >> dc >> hm >> dm >> n >> d >> h;
    bool ok = false;
    for (int i = 0; i <= n && !ok; ++i) {
      long long hn = hc + i * h, dn = dc + (n - i) * d;
      long long x = (hm - 1) / dn, y = (hn - 1) / dm;
      ok |= x <= y;
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}