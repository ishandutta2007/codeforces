#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int K = 105;
const int N = 100010;
const int MOD = 998244353;

inline int add (int x, int y) {
  x += y; if (x >= MOD) x -= MOD; return x;
}

inline int sub (int x, int y) {
  x -= y; if (x < 0) x += MOD; return x;
}

int n, k, len, a[N], f[K][N], sum[N], freq[K];

int main() {
  cin >> n >> k >> len;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == -1) a[i] = 0;
  }
  sum[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ++freq[a[i]];
    if (i > len) --freq[a[i - len]];
    for (int j = 1; j <= k; ++j) {
      if (a[i] == 0 or a[i] == j) {
        f[j][i] = sum[i - 1];
      }
      if (i >= len and freq[0] + freq[j] == len) {
        f[j][i] = sub(f[j][i], sum[i - len]);
        f[j][i] = add(f[j][i], f[j][i - len]);
      }
      sum[i] = add(sum[i], f[j][i]);
    }
  }
  printf("%d\n", sum[n]);
  return 0;
}