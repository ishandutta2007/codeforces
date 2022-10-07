#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) {
      std::cin >> x;
    }
    if (std::is_sorted(a.begin(), a.end())) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}