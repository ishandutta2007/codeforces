#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> a;
  a.push_back(0);
  while (a.back() < 1000000000) {
    int n = a.size();
    int x = n / 3, y = n / 3, z = n / 3;
    z += n % 3 > 0;
    y += n % 3 > 1;
    a.push_back(2 * (x * y + x * z + y * z));
  }

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::cout << std::lower_bound(a.begin(), a.end(), n) - a.begin() << "\n";
  }
}