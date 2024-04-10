#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int R, C, n;
    std::cin >> R >> C >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    bool o0 = false, o1 = false;
    long long s0 = 0, s1 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= 2 * R) {
        s0 += a[i] / R;
        o0 |= a[i] / R > 2;
      }
      if (a[i] >= 2 * C) {
        s1 += a[i] / C;
        o1 |= a[i] / C > 2;
      }
    }
    if ((s0 >= C && (!(C & 1) || o0)) || (s1 >= R && (!(R & 1) || o1))) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}