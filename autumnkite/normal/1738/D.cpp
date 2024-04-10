#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> pos(n + 2);
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
      --b[i];
      pos[b[i] + 1].push_back(i);
    }
    int k = 0;
    while (k < n && b[k] >= k) {
      ++k;
    }
    std::vector<int> a;
    if (!pos[0].empty()) {
      a.push_back(-1);
    } else {
      a.push_back(n);
    }
    for (int i = 0; i < (int)a.size(); ++i) {
      for (int x : pos[a[i] + 1]) {
        if (pos[x + 1].empty()) {
          a.push_back(x);
        }
      }
      for (int x : pos[a[i] + 1]) {
        if (!pos[x + 1].empty()) {
          a.push_back(x);
        }
      }
    }
    a.erase(a.begin());
    std::cout << k << "\n";
    for (int x : a) {
      std::cout << x + 1 << " ";
    }
    std::cout << "\n";
  }
}