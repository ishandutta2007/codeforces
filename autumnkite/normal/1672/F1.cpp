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
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      mp[a[i]].push_back(i);
    }
    std::vector<int> b(n);
    while (!mp.empty()) {
      std::vector<int> id;
      auto it = mp.begin();
      while (it != mp.end()) {
        id.push_back(it->second.back());
        it->second.pop_back();
        if (it->second.empty()) {
          it = mp.erase(it);
        } else {
          ++it;
        }
      }
      int c = id.size();
      for (int i = 0; i < c; ++i) {
        b[id[i]] = a[id[(i + 1) % c]];
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << b[i] << " \n"[i == n - 1];
    }
  }
}