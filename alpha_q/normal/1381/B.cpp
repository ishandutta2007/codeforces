#include <bits/stdc++.h>

using namespace std;

const int N = 4010;

bitset <N> dp;
int t, n, p[N], vals[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n + n; ++i) {
      scanf("%d", p + i);
    }
    int m = 0, last = n + n;
    while (last) {
      int at = 1;
      for (int i = 1; i <= last; ++i) {
        if (p[i] > p[at]) at = i;
      }
      vals[++m] = last - at + 1, last = at - 1;
    }
    for (int i = 0; i <= n + n; ++i) {
      dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
      dp |= dp << vals[i];
    }
    puts(dp[n] ? "YES" : "NO");
  }
  return 0;
}