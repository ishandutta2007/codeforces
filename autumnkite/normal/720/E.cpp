#include <bits/stdc++.h>

int main() {
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto &fin = std::cin;
  auto &fout = std::cout;
#else
  std::ifstream fin("time.in");
  std::ofstream fout("time.out");
#endif

  int T;
  fin >> T;
  while (T--) {
    int n;
    fin >> n;
    std::string tmp;
    fin >> tmp;
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[i] = tmp[i] - '0';
    }
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
      fin >> a[i];
    }

    std::vector<int> l;
    std::size_t nonzero_p = 0;
    bool updated = false;

    auto check0 = [&]() {
      return nonzero_p == l.size();
    };

    auto check1 = [&]() {
      return nonzero_p + 1 == l.size() && l[nonzero_p] == 1;
    };

    for (int i = 0; i < n; ++i) {
      int p = pos[i];

      auto LCP = [&](int j) {
        int k = 0;
        while (k < 10 && a[i][(p + k) % 10] == a[i][(j + k) % 10]) {
          ++k;
        }
        if (check0()) {
          return std::make_pair(0, std::min(10 - std::max(j, p), k));
        } else if (k < 10) {
          return std::make_pair(0, k);
        } else {
          return std::make_pair(1, 10 - std::max(j, p));
        }
      };

      std::pair<int, int> max(0, 0);
      for (int j = 0; j < 10; ++j) {
        if (j != p) {
          max = std::max(max, LCP(j));
        }
      }
      auto nl = LCP(p + 1);
      if (max.first) {
        l.push_back(max.second);
      } else if (check1() && 10 - p <= max.second) {
        while (nonzero_p < l.size()) {
          l[nonzero_p++] = 0;
        }
        l.push_back(max.second);
        if (!l[nonzero_p]) {
          ++nonzero_p;
        }
        updated = true;
      } else if (check0()) {
        l.push_back(max.second);
        if (max.second) {
          updated = true;
        } else {
          ++nonzero_p;
        }
      } else {
        break;
      }
      if (nl != max) {
        break;
      }
    }
    if (!updated) {
      fout << 0 << "\n";
      continue;
    }
    bool need_minus = false;
    for (int i = l.size(); i < n; ++i) {
      need_minus |= pos[i];
    }
    if (need_minus) {
      int p = (int)l.size() - 1;
      while (!l[p]) {
        l[p] = 9;
        --p;
      }
      --l[p];
      for (int i = l.size(); i < n; ++i) {
        l.push_back(9 - pos[i]);
      }
      p = n - 1;
      while (l[p] == 9) {
        l[p] = 0;
        --p;
      }
      ++l[p];
    } else {
      for (int i = l.size(); i < n; ++i) {
        l.push_back(0);
      }
    }
    int p = 0;
    while (p + 1 < n && !l[p]) {
      ++p;
    }
    for (int i = p; i < n; ++i) {
      fout << l[i];
    }
    fout << "\n";
  }
}