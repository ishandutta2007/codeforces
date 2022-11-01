#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n, x, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x;
    int tot = 0, ans = -1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      a[i] %= x, tot += a[i], tot %= x;
      if (tot) ans = i;
    }
    tot = 0;
    for (int i = n, j = 1; j <= n; --i, ++j) {
      tot += a[i], tot %= x;
      if (tot) ans = max(ans, j);
    }
    cout << ans << '\n';
  }
  return 0;
}