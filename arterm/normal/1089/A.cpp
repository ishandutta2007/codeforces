#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int B = 205;
const int inf = 1e9;
pair<int, int> d[6][4][B][B];

void pre() {
  for (int i = 0; i < 6; ++i) {
    for (int my = 0; my < 4; ++my) {
      for (int j = 0; j < B; ++j) {
        for (int k = 0; k < B; ++k) {
          d[i][my][j][k] = {-1, -1};
        }
      }
    }
  }
  d[0][0][0][0] = {0, 0};
  for (int i = 0; i < 6; ++i) {
    for (int my = 0; my < 4; ++my) {
      for (int a = 0; a < B; ++a) {
        for (int b = 0; b < B; ++b) {
          if (d[i][my][a][b].first == -1 || my >= 3 || i - my >= 3) {
            continue;
          }
          int C = i == 4 ? 15 : 25;
          auto relax = [&](int x, int y) {
            if (a + x >= B || b + y >= B) {
              return;
            }
            int w = x > y;
            if (d[i + 1][my + w][a + x][b + y].first == -1) {
              d[i + 1][my + w][a + x][b + y] = {x, y};
            }
          };
          for (int m = 0; m <= C - 2; ++m) {
            relax(C, m);
            relax(m, C);
          }
          for (int m = C + 1; m < B; ++m) {
            relax(m, m - 2);
            relax(m - 2, m);
          }
        }
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  int N = -1, MY = -1;
  for (int n = 0; n < 6; ++n) {
    for (int my = 0; my < 4; ++my) {
      if (my < 3 && n - my < 3) {
        continue;
      }
      if (d[n][my][a][b].first == -1) {
        continue;
      }
      if (N == -1 || 2 * MY - N < 2 * my - n) {
        N = n, MY = my;
      }
    }
  }
  if (N == -1) {
    cout << "Impossible\n";
    return;
  }
  cout << MY << ":" << N - MY << '\n';
  int n = N, my = MY;
  vector<pair<int, int>> v;
  while (n > 0) {
    auto [x, y] = d[n][my][a][b];
    v.emplace_back(x, y);
    --n;
    my -= x > y;
    a -= x;
    b -= y;
  }
  reverse(v.begin(), v.end());
  for (auto p : v) {
    cout << p.first << ':' << p.second << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  pre();
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}