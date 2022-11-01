#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;
const int MOD = 1e9 + 7;

char s[N];
int n, q, p[N], two[N];

int main() {
  two[0] = 1;
  for (int i = 1; i < N; ++i) {
    two[i] = (two[i - 1] << 1);
    if (two[i] >= MOD) two[i] -= MOD;
  }
  scanf("%d %d %s", &n, &q, s + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + (s[i] - '0');
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int len = r - l + 1;
    int one = p[r] - p[l - 1];
    int zero = len - one;
    int ans = (two[one] - 1) * 1LL * two[zero] % MOD;
    if (ans < 0) ans += MOD;
    printf("%d\n", ans);
  }
  return 0;
}