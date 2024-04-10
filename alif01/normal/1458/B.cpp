#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = N*N*2;
int n, s, a[N], b[N], f[2][N][N*N*4];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", a + i, b + i);
    s += a[i];
    a[i] -= b[i];
  }
  s <<= 1;
  for (int k = -s; k <= s; k++) f[0][0][k+M] = -10 * s;
  f[0][0][0+M] = 0;
  for (int i = 1; i <= n; i++) {
    int I = i & 1;
    for (int j = 0; j <= i; j++) {
      for (int k = -s; k <= s; k++) {
        f[I][j][k+M] = -10 * s;
      }
    }
    for (int j = 0; j < i; j++) {
      for (int k = -s; k <= s; k++) if (f[!I][j][k+M] >= 0) {
        f[I][j][k+b[i]+M] = max(f[I][j][k+b[i]+M], f[!I][j][k+M]+b[i]);
        f[I][j+1][k-2*a[i]+M] = max(f[I][j+1][k-2*a[i]+M], f[!I][j][k+M]+2*b[i]);
      }
    }
  }
  int I = n & 1;
  for (int j = 1; j <= n; j++) {
    int ans = -10 * s;
    for (int k = -s; k <= s; k++) {
      ans = max(ans, f[I][j][k+M] - (k > 0 ? k : 0));
    }
    printf("%d.%d\n", ans / 2, ans & 1 ? 5 : 0);
  }
}