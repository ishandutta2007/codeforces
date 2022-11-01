#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const int MOD = 1e9 + 7;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int n;
ll f[N][4];
char a[N], b[N];

int main() {
  cin >> n;
  scanf("%s %s", a + 1, b + 1);
  f[0][3] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < 4; ++mask) {
      if (a[i] == '?') {
        if (b[i] == '?') {
          f[i][mask] += 10 * f[i - 1][mask];
          f[i][mask] += 45 * f[i - 1][mask | 1];
          f[i][mask] += 45 * f[i - 1][mask | 2];
          f[i][mask] %= MOD;
        } else {
          int cur = b[i] - '0';
          f[i][mask] += f[i - 1][mask];
          f[i][mask] += cur * f[i - 1][mask | 1];
          f[i][mask] += (9 - cur) * f[i - 1][mask | 2];
          f[i][mask] %= MOD;
        }
      } else {
        int cur = a[i] - '0';
        if (b[i] == '?') {
          f[i][mask] += f[i - 1][mask];
          f[i][mask] += cur * f[i - 1][mask | 2];
          f[i][mask] += (9 - cur) * f[i - 1][mask | 1];
          f[i][mask] %= MOD;
        } else {
          int yo = b[i] - '0';
          if (cur == yo) f[i][mask] += f[i - 1][mask];
          else if (cur < yo) f[i][mask] += f[i - 1][mask | 1];
          else f[i][mask] += f[i - 1][mask | 2];
          f[i][mask] %= MOD;
        }
      }
    }
  }
  cout << f[n][0] << '\n';
  return 0;
}