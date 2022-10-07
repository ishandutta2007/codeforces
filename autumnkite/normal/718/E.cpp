#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  
  std::vector<char> v(s.begin(), s.end());
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int m = v.size();
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();
  }

  std::vector<std::vector<int>> dis(m, std::vector<int>(m, 2 * m));
  for (int i = 0; i < m; ++i) {
    dis[i][i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < i + 2 * m && j < n; ++j) {
      dis[a[i]][a[j]] = std::min(dis[a[i]][a[j]], j - i + 1);
      dis[a[j]][a[i]] = std::min(dis[a[j]][a[i]], j - i + 1);
    }
  }
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  std::vector<std::vector<int>> x(n, std::vector<int>(m, 2 * m));
  int max = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = std::max(i - 2 * m, 0); j < i + 2 * m && j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        x[i][k] = std::min(x[i][k], abs(i - j) + dis[a[j]][k]);
      }
    }
  }

  std::map<std::vector<int>, int> cnt;
  for (int i = 0; i < n; ++i) {
    ++cnt[x[i]];
  }

  int L = 2 * m - 1;
  while (L >= 0) {
    auto check = [&](const auto &x, const auto &y) {
      for (int k = 0; k < m; ++k) {
        if (x[k] + y[k] + 1 < L) {
          return false;
        }
      }
      return true;
    };
    long long ans = 0;
    for (const auto &p : cnt) {
      for (const auto &q : cnt) {
        if (check(p.first, q.first)) {
          ans += 1ll * p.second * q.second;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      ans -= check(x[i], x[i]);
      for (int j = std::max(0, i - L + 1); j < i; ++j) {
        ans -= check(x[i], x[j]) * 2;
      }
    }
    if (ans) {
      std::cout << L << " " << ans / 2 << "\n";
      break;
    }
    --L;
  }
}