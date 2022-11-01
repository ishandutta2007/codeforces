#include <bits/stdc++.h>

using namespace std;

const int N = 10002;
const int INF = 1e8 + 5;

char a[N], b[N];
int n, m, f[N][N], to[N];

int main() {
  scanf("%s %s", a + 1, b + 1);
  n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == '.') {
      to[i] = -1;
    } else {
      to[i] = -1;
      int tot = 1;
      for (int j = i + 1; j <= n; ++j) {
        a[j] == '.' ? --tot : ++tot;
        if (!tot) {
          to[i] = j;
          break;
        }
      }
    }
  }
  for (int i = n + 1; i; --i) {
    for (int j = m + 1; j; --j) {
      if (i > n and j > m) {
        f[i][j] = 0;
        continue;
      }
      if (i > n) {
        f[i][j] = INF;
        continue;
      }
      f[i][j] = 1 + f[i + 1][j];
      if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i + 1][j + 1]);
      if (~to[i]) f[i][j] = min(f[i][j], f[to[i] + 1][j]);
    }
  }
  cout << f[1][1] << '\n';
  return 0;
}