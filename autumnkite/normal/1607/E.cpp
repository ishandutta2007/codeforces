#include <bits/stdc++.h>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;
  int x = 0, y = 0, sx = 0, sy = 0, tx = n, ty = m;
  int ansx = 0, ansy = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'L') {
      --y;
    } else if (s[i] == 'R') {
      ++y;
    } else if (s[i] == 'U') {
      --x;
    } else {
      ++x;
    }
    sx = std::max(sx, -x);
    tx = std::min(tx, n - x);
    sy = std::max(sy, -y);
    ty = std::min(ty, m - y);
    if (sx == tx || sy == ty) {
      break;
    }
    ansx = sx, ansy = sy;
  }
  std::cout << ansx + 1 << " " << ansy + 1 << "\n";
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