#include <bits/stdc++.h>

using namespace std;

int n, k;
char g[7][110];

int main() {
  cin >> n >> k;
  cout << "YES\n";
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 107; ++j) {
      g[i][j] = '.';
    }
  }
  for (int i = 2, j = n - 1; k > 1 and i < j; ++i, --j, k -= 2) {
    g[2][i] = g[2][j] = '#';
  }
  for (int i = 2, j = n - 1; k > 1 and i < j; ++i, --j, k -= 2) {
    g[3][i] = g[3][j] = '#';
  }
  if (k) g[2][1 + n >> 1] = '#', --k;
  if (k) g[3][1 + n >> 1] = '#', --k;
  assert(k == 0);
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= n; ++j) {
      putchar(g[i][j]);
    }
    puts("");
  }
  return 0;
}