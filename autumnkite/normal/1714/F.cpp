#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, a, b, c;
    std::cin >> n >> a >> c >> b;
    if ((a + b + c) & 1) {
      std::cout << "NO\n";
      continue;
    }
    int s = (a + b + c) / 2;
    if (s < a || s < b || s < c) {
      std::cout << "NO\n";
      continue;
    }
    int x = s - c, y = s - b, z = s - a;
    if (x + y + z + 1 > n || std::max({x, y, z}) == x + y + z) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    int idx = 3;

    auto add_chain = [&](int st, int len, int end) {
      for (int i = 1; i < len; ++i) {
        std::cout << st + 1 << " " << idx + 1 << "\n";
        st = idx++;
      }
      std::cout << st + 1 << " " << end + 1 << "\n";
    };

    if (x == 0) {
      add_chain(0, y, 1);
      add_chain(0, z, 2);
    } else if (y == 0) {
      add_chain(1, x, 0);
      add_chain(1, z, 2);
    } else if (z == 0) {
      add_chain(2, x, 0);
      add_chain(2, y, 1);
    } else {
      ++idx;
      add_chain(3, x, 0);
      add_chain(3, y, 1);
      add_chain(3, z, 2);
    }
    if (x + y + z + 1 < n) {
      add_chain(0, n - x - y - z - 1, n - 1);
    }
  }
}