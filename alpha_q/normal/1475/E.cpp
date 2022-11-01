#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int MOD = 1e9 + 7;

int t, n, k, a[N], c[N][N];

int main() {
  for (int i = 0; i < N; ++i) c[i][0] = 1;
  for (int i = 1; i < N; ++i) for (int j = 1; j <= i; ++j) {
    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, greater <int> ());
    int ans = 1;
    for (int i = 1, j = 1; i <= n; i = j) {
      while (j <= n and a[j] == a[i]) ++j;
      int tot = j - i;
      if (k > tot) k -= tot;
      else {
        ans = c[tot][k]; break;
      } 
    }
    printf("%d\n", ans);
  }
  return 0;
}