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
    std::vector<int> odd(n);
    std::map<int, std::set<int>> S;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
      odd[a[i]] ^= 1;
      S[a[i]].insert(i);
    }

    if (std::accumulate(odd.begin(), odd.end(), 0) > 1) {
      std::cout << "NO\n";
      continue;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (odd[i] && S[i].size() == 1 && *S[i].begin() == n / 2) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "NO\n";
      continue;
    }

    int odd_v = std::find(odd.begin(), odd.end(), 1) - odd.begin();

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    
    auto swap = [&](int x, int y) {
      S[a[x]].erase(x), S[a[y]].erase(y);
      std::swap(p[x], p[y]);
      std::swap(a[x], a[y]);
      S[a[x]].insert(x), S[a[y]].insert(y);
    };

    int l = 0, r = n - 1;
    while (l < r) {
      auto it = S.begin();
      bool ok = false;
      while (it != S.end()) {
        if (it->first == odd_v) {
          ++it;
          continue;
        }
        int x = *it->second.begin();
        int y = *(++it->second.begin());
        if (x == l && y == r) {
          ++it;
          continue;
        }
        if (a[l] == odd_v && S[odd_v].size() == 1 && x == n / 2) {
          ++it;
          continue;
        }
        if (a[r] == odd_v && S[odd_v].size() == 1 && y == n / 2) {
          ++it;
          continue;
        }
        if (x == l) {
          swap(l, y);
          swap(r, y);
        } else if (y == r) {
          swap(r, x);
          swap(l, x);
        } else {
          swap(l, x);
          swap(r, y);
        }
        ok = true;
        break;
      }
      if (!ok) {
        if (r - l >= 3) {
          swap(l, l + 1);
          swap(r, l + 2);
        } else if (r - l == 1) {
          swap(l, r);
        } else if (a[l] == a[l + 1]) {
          swap(l, l + 1);
          swap(l + 1, r);
        } else if (a[r] == a[r - 1]) {
          swap(r, r - 1);
          swap(r - 1, l);
        }
      }
      S[a[l]].erase(l);
      S[a[r]].erase(r);
      if (S[a[l]].empty()) {
        S.erase(a[l]);
      }
      if (S[a[r]].empty()) {
        S.erase(a[r]);
      }
      ++l, --r;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      std::cout << p[i] + 1 << " ";
    }
    std::cout << "\n";
  }
}