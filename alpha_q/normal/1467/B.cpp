#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

bool bad[N];
int t, n, a[N];

bool check (int l, int mid, int r) {
  return (mid > l and mid > r) or (mid < l and mid < r);
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
      bad[i] = 0;
    }
    for (int i = 2; i < n; ++i) {
      bad[i] = check(a[i - 1], a[i], a[i + 1]);
      cur += bad[i];
    }
    int ans = cur;
    if (n > 1 and bad[2]) {
      ans = min(ans, cur - 1);
    }
    if (n > 1 and bad[n - 1]) {
      ans = min(ans, cur - 1);
    }
    for (int i = 2; i < n; ++i) {
      int tmp = cur - bad[i] - bad[i - 1] - bad[i + 1];
      if (a[i - 1] == a[i + 1]) {
        ans = min(ans, tmp);
      } else {
        ans = min(ans, tmp + (i + 2 <= n ? check(a[i - 1], a[i + 1], a[i + 2]) : 0));
        ans = min(ans, tmp + (i - 2 >= 1 ? check(a[i - 2], a[i - 1], a[i + 1]) : 0));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}