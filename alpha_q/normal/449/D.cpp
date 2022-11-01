#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, x, f[1 << 20], two[1 << 20];

int main() {
  two[0] = 1;
  for (int i = 1; i < 1 << 20; ++i) {
    two[i] = two[i - 1] << 1;
    if (two[i] >= MOD) two[i] -= MOD;
  }
  cin >> n;
  while (n--) {
    scanf("%d", &x); ++f[x];
  }
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 1 << 20; ++j) {
      if (~j & 1 << i) f[j] += f[j ^ 1 << i];
    }
  }
  int ans = 0;
  for (int i = 0; i < 1 << 20; ++i) {
    (__builtin_popcount(i) & 1) ? ans -= two[f[i]] : ans += two[f[i]]; 
    if (ans >= MOD) ans -= MOD; if (ans < 0) ans += MOD;
  }
  cout << ans << '\n';
  return 0;
}