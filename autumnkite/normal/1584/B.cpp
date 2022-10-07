#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    int rem = (n % 3) * (m % 3);
    std::cout << (n * m - rem) / 3 + rem - rem / 2 << "\n";
  }
}