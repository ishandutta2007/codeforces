#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int MOD = 1e9 + 7;

char g[N][N];
int n, m, f[2][N][N], sum[2][N][N], dn[N][N], rt[N][N];

inline int add (int x, int y) {
  x += y; if (x >= MOD) x -= MOD; return x;
}

inline int get (int idx, int p, int l, int r) {
  int ret = 0;
  if (idx == 0) {
    ret = sum[0][l][p] - sum[0][r + 1][p];
  } else {
    ret = sum[1][p][l] - sum[1][p][r + 1];
  }
  if (ret < 0) ret += MOD;
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  if (n == 1 and m == 1) {
    cout << (g[1][1] == '.') << '\n';
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    int tot = 0;
    for (int j = m; j >= 1; --j) {
      rt[i][j] = m - j - tot;
      if (g[i][j] == 'R') ++tot;
    }
  }
  for (int j = 1; j <= m; ++j) {
    int tot = 0;
    for (int i = n; i >= 1; --i) {
      dn[i][j] = n - i - tot;
      if (g[i][j] == 'R') ++tot;
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << rt[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     cout << dn[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for (int i = n; i >= 1; --i) {
    for (int j = m; j >= 1; --j) {
      if (i == n and j == m) {
        f[0][i][j] = f[1][i][j] = (g[i][j] == 'R' ? 0 : 1);
        sum[0][i][j] = add(sum[0][i + 1][j], f[0][i][j]);
        sum[1][i][j] = add(sum[1][i][j + 1], f[1][i][j]);
        continue;
      }
      // go right
      f[0][i][j] = get(1, i, j + 1, j + rt[i][j]);
      sum[0][i][j] = add(sum[0][i + 1][j], f[0][i][j]);
      // for (int k = 1; k <= rt[i][j]; ++k) {
      //   f[0][i][j] = add(f[0][i][j], f[1][i][j + k]);
      // }
      // go down
      f[1][i][j] = get(0, j, i + 1, i + dn[i][j]);
      // for (int k = 1; k <= dn[i][j]; ++k) {
      //   f[1][i][j] = add(f[1][i][j], f[0][i + k][j]);
      // }
      sum[1][i][j] = add(sum[1][i][j + 1], f[1][i][j]);
      // cout << i << " " << j << " ---> " << f[0][i][j] << " " << f[1][i][j] << endl;
    }
  }
  // cout << f[0][1][1] << " " << f[1][1][1] << endl;
  cout << add(f[0][1][1], f[1][1][1]) << '\n';
  return 0;
}