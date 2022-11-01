#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, ans[N][N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(ans, 0, sizeof ans);
    for (int i = 1; i < n; i += 2) {
      ans[i][i] = ans[i + 1][i + 1] = ans[i][i + 1] = ans[i + 1][i] = 1;
    }
    if (n & 1) {
      for (int i = n - 2; i <= n; ++i) {
        ans[i][n] = ans[n][i] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) printf("%d ", ans[i][j]);
      puts("");
    }
  }
  return 0;
}