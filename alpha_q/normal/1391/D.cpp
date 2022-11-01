#include <bits/stdc++.h>

using namespace std;

const int M = 10;
const int N = 1000010;
const int INF = 2e8 + 5;

char g[5][N];
vector <int> to[6969];
int n, m, f[N][M], diff[N][M];

inline int get (int x, int pos) {
  return (x >> pos) & 1;
}

int main() {
  cin >> n >> m;
  if (n >= 4) {
    cout << "-1\n";
    return 0;
  }
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", g[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (g[k][i] - '0' != get(j, k)) {
          ++diff[i][j];
        }
      }
    }
  }
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      bool ok = 1;
      for (int k = 0; k + 1 < n; ++k) {
        if ((get(i, k) + get(j, k) + get(i, k + 1) + get(j, k + 1)) % 2 == 0) {
          ok = 0;
          break;
        }
      }
      if (ok) to[i].emplace_back(j);
    }
  }
  for (int i = m - 1; i; --i) {
    for (int j = 0; j < 1 << n; ++j) {
      f[i][j] = INF;
      for (int k : to[j]) f[i][j] = min(f[i][j], f[i + 1][k] + diff[i][k]);
    }
  }
  int ans = INF;
  for (int i = 0; i < 1 << n; ++i) ans = min(ans, diff[0][i] + f[1][i]);
  cout << ans << '\n';
  return 0;
}