#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int MOD = 998244353;

int f[N][N];
char s[N], t[N];

int main() {
  scanf("%s %s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  for (int l = 1; l <= n; ++l) {
    for (int r = n; r >= l; --r) {
      int pos = r - l + 1;
      if (l == 1 and r >= m) f[l][r] = 1;
      char cur = s[pos + 1];
      if (l > 1 and (l - 1 > m or t[l - 1] == cur)) {
        f[l][r] += f[l - 1][r];
        if (f[l][r] >= MOD) f[l][r] -= MOD;
      } 
      if (r < n and (r + 1 > m or t[r + 1] == cur)) {
        f[l][r] += f[l][r + 1];
        if (f[l][r] >= MOD) f[l][r] -= MOD;
      }
    }
  }
  int ans = 0;
  for (int l = 1; l <= n; ++l) {
    if (l > m or s[1] == t[l]) {
      ans += f[l][l];
      if (ans >= MOD) ans -= MOD;
      ans += f[l][l];
      if (ans >= MOD) ans -= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}