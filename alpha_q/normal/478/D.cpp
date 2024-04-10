#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int MOD = 1e9 + 7;

int r, g, h, s, f[N], res;

int main() {
  scanf("%d %d", &r, &g);
  h = int((sqrt(8 * (r + g) + 1) - 1) / 2.0);
  f[0] = 1, s = h * (h + 1) / 2;
  for (int i = 1; i <= h; ++i) {
    for (int j = g; j >= i; --j) {
      f[j] += f[j - i];
      if (f[j] >= MOD) f[j] -= MOD;
    }
  }
  for (int i = 0; i <= g; ++i) {
    if (r + i >= s) {
      res += f[i];
      if (res >= MOD) res -= MOD;
    }
  } 
  printf("%d\n", res);
  return 0;
}