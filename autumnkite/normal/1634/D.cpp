#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    
    auto query = [&](int i, int j, int k) {
      std::cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
      int x;
      std::cin >> x;
      return x;
    };

    int k = 2, max = query(0, 1, 2);
    int lst1 = max;
    bool same1 = true;
    for (int i = 3; i < n; ++i) {
      int t = query(0, 1, i);
      same1 &= lst1 == t;
      lst1 = t;
      if (t > max) {
        k = i;
        max = t;
      }
    }
    lst1 = max;

    int p = 1;
    int lst2 = max;
    bool same2 = true;
    for (int i = 2; i < n; ++i) {
      if (i != k) {
        int t = query(0, k, i);
        same2 &= lst2 == t;
        lst2 = t;
        if (t > max) {
          p = i;
          max = t;
        }
      }
    }
    if (max == lst1 && same1 && !same2) {
      std::cout << "! " << 1 << " " << 2 << std::endl;
    } else if (same2) {
      std::cout << "! " << 1 << " " << k + 1 << std::endl;
    } else {
      std::cout << "! " << p + 1 << " " << k + 1 << std::endl;
    }
  }
}