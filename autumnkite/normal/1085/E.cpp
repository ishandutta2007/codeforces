#include <bits/stdc++.h>

class map {
  std::vector<int> p;
  std::vector<bool> vis;
  bool ok;

public:
  map(int n) : p(n, -1), vis(n), ok(true) {}

  bool check(int x, int y) const {
    return ok && (p[x] == y || (p[x] == -1 && !vis[y]));
  }

  void insert(int x, int y) {
    if (check(x, y)) {
      p[x] = y;
      vis[y] = true;
    } else {
      ok = false;
    }
  }

  bool valid() const {
    return ok;
  }

  std::vector<int> get() const {
    auto res(p);
    int j = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
      if (res[i] == -1) {
        while (vis[j]) {
          ++j;
        }
        res[i] = j++;
      }
    }
    return res;
  }
};

void solve() {
  int k;
  std::cin >> k;
  std::string s, a, b;
  std::cin >> s >> a >> b;
  int n = s.size();
  int l = 0;
  while (l < n && a[l] == b[l]) {
    ++l;
  }

  auto get_string = [&](const std::vector<int> &p) {
    std::string res;
    for (int x : p) {
      res += 'a' + x;
    }
    return res;
  };

  map A(k);
  for (int i = 0; i < n; ++i) {
    if (i >= l) {
      for (char c = a[i] + 1; c < (i == l ? b[i] : 'a' + k); ++c) {
        if (A.check(s[i] - 'a', c - 'a')) {
          A.insert(s[i] - 'a', c - 'a');
          std::cout << "YES\n";
          std::cout << get_string(A.get()) << "\n";
          return;
        }
      }
    }
    A.insert(s[i] - 'a', a[i] - 'a');
  }
  if (A.valid()) {
    std::cout << "YES\n";
    std::cout << get_string(A.get()) << "\n";
    return;
  }

  map B(k);
  for (int i = 0; i < n; ++i) {
    if (i >= l) {
      for (char c = b[i] - 1; c > (i == l ? a[i] : 'a' - 1); --c) {
        if (B.check(s[i] - 'a', c - 'a')) {
          B.insert(s[i] - 'a', c - 'a');
          std::cout << "YES\n";
          std::cout << get_string(B.get()) << "\n";
          return;
        }
      }
    }
    B.insert(s[i] - 'a', b[i] - 'a');
  }
  if (B.valid()) {
    std::cout << "YES\n";
    std::cout << get_string(B.get()) << "\n";
    return;
  }
  
  std::cout << "NO\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}