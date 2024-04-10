#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 505;
const int MOD = 1e9 + 7;

int n, x, two[N], child[N];

int main() {
  scanf("%d", &n);
  two[0] = 1;
  for (int i = 1; i <= n; ++i) {
    two[i] = 2 * two[i - 1] % MOD;
  }
  for (int i = 0; i <= n; ++i) {
    --two[i];
    if (two[i] < 0) two[i] += MOD;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (x != -1) ++child[x];
  }
  int ans = two[n - 1];
  for (int i = 1; i <= n; ++i) {
    ans -= two[child[i]];
    if (ans < 0) ans += MOD;
  }
  printf("%d\n", ans);
  return 0;
}