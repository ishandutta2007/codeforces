#include <bits/stdc++.h>

constexpr int C = 52;

int get(char x) {
  return isupper(x) ? x - 'A' : x - 'a' + 26;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    std::vector<std::array<std::vector<int>, C>> pos(n);
    std::vector<std::vector<int>> id(n);
    std::vector<std::vector<std::array<int, C>>> nxt(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      id[i].resize(a[i].size());
      for (int j = 0; j < (int)a[i].size(); ++j) {
        id[i][j] = pos[i][get(a[i][j])].size();
        pos[i][get(a[i][j])].push_back(j);
      }
      nxt[i].resize(a[i].size() + 1);
      nxt[i][a[i].size()].fill(-1);
      for (int j = (int)a[i].size() - 1; j >= 0; --j) {
        nxt[i][j] = nxt[i][j + 1];
        nxt[i][j][get(a[i][j])] = j;
      }
    }

    std::vector<std::vector<int>> f(C, std::vector<int>(1 << n));
    std::vector<std::vector<int>> g(C, std::vector<int>(1 << n, -1));
    std::vector<std::tuple<std::vector<int>, int, int>> st;
    for (int c = 0; c < C; ++c) {
      for (int S = 0; S < (1 << n); ++S) {
        std::vector<int> p(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
          if ((S >> i & 1) < (int)pos[i][c].size()) {
            p[i] = pos[i][c][S >> i & 1];
          } else {
            ok = false;
            break;
          }
        }
        if (ok) {
          st.emplace_back(p, c, S);
          f[c][S] = 1;
        }
      }
    }
    std::sort(st.begin(), st.end());

    int ans = 0;
    int ans_st = -1;
    for (auto [p, c, S] : st) {
      if (f[c][S]) {
        if (ans < f[c][S]) {
          ans = f[c][S];
          ans_st = c << n | S;
        }
        for (int nc = 0; nc < C; ++nc) {
          int nS = 0;
          bool ok = true;
          for (int i = 0; i < n; ++i) {
            int j = nxt[i][p[i] + 1][nc];
            if (j == -1) {
              ok = false;
              break;
            }
            nS |= id[i][j] << i;
          }
          if (ok) {
            if (f[nc][nS] < f[c][S] + 1) {
              f[nc][nS] = f[c][S] + 1;
              g[nc][nS] = c << n | S;
            }
          }
        }
      }
    }
    std::cout << ans << "\n";
    std::string res;
    for (int i = 0, now = ans_st; i < ans; ++i) {
      int c = now >> n, S = now ^ (c << n);
      res += c < 26 ? 'A' + c : 'a' + c - 26;
      now = g[c][S];
    }
    std::reverse(res.begin(), res.end());
    std::cout << res << "\n";
  }
}