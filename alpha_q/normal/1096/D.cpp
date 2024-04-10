#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

string bad = "#hard#";
int n; char s[N]; ll a[N], f[N][7];

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j < 4; ++j) {
      if (s[i] == bad[j + 1]) {
        f[i][j] = a[i] + f[i + 1][j];
        if (j < 3) f[i][j] = min(f[i][j], f[i + 1][j + 1]);
      } else {
        f[i][j] = f[i + 1][j];
      }
    }
  }
  ll ans = min(min(f[1][0], f[1][1]), min(f[1][2], f[1][3]));
  printf("%lld\n", ans);
  return 0;
}