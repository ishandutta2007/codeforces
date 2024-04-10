#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int INF = 1e8 + 5;

int n, m, g[N][N], d[N][N];

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
  if (g[1][n]) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = INF;
      }
      d[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i != j and !g[i][j]) d[i][j] = 1;
      }
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = INF;
      }
      d[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (g[i][j]) d[i][j] = 1;
      }
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
  if (d[1][n] > INF / 2) d[1][n] = -1;
  cout << d[1][n] << '\n';
  return 0;
}