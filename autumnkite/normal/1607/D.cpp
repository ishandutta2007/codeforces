#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::string col;
  std::cin >> col;
  std::vector<int> p, q;
  for (int i = 0; i < n; ++i) {
    if (col[i] == 'B') {
      p.push_back(a[i]);
    } else {
      q.push_back(a[i]);
    }
  }
  std::sort(p.begin(), p.end());
  std::sort(q.begin(), q.end(), std::greater<int>());
  bool ok = true;
  for (int i = 0; i < (int)p.size(); ++i) {
    ok &= i < p[i];
  }
  for (int i = 0; i < (int)q.size(); ++i) {
    ok &= n - i >= q[i];
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