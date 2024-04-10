#include <bits/stdc++.h>

using namespace std;

const int N = 469;
const int INF = 1e8 + 69;

int t, n, a[N], f[N][N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n + n; ++j) {
        if (j < i) {
          f[i][j] = INF;
          continue;
        }
        f[i][j] = min(f[i][j - 1], abs(a[i] - j) + f[i - 1][j - 1]);
      }
    }
    cout << f[n][n + n] << '\n';
  }
  return 0;
}