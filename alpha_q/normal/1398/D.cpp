#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 205;

int R, G, B;
ll f[N][N][N];
ll r[N], g[N], b[N];

int main() {
  cin >> R >> G >> B;
  for (int i = 1; i <= R; ++i) cin >> r[i];
  for (int i = 1; i <= G; ++i) cin >> g[i];
  for (int i = 1; i <= B; ++i) cin >> b[i];
  sort(r + 1, r + R + 1);
  sort(g + 1, g + G + 1);
  sort(b + 1, b + B + 1);
  for (int i = 0; i <= R; ++i) {
    for (int j = 0; j <= G; ++j) {
      for (int k = 0; k <= B; ++k) {
        f[i][j][k] = 0;
        if (i and j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + r[i] * g[j]);
        if (i and k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + r[i] * b[k]);
        if (j and k) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1] + g[j] * b[k]);
      }
    }
  }
  cout << f[R][G][B] << '\n';
  return 0;
}