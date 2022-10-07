#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  bool ok = true;
  for (int i = 0; i < n && ok; ++i) {
    bool flag = false;
    for (int j = 2; j <= i + 2 && !flag; ++j) {
      flag |= a[i] % j != 0;
    }
    ok &= flag;
  }
  if (ok) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}