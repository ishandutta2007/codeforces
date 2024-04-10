#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int a[maxN], b[maxN];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &b[i]);
    }
    auto check = [&](int mid) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (cnt <= b[i] && mid - cnt - 1 <= a[i]) {
          ++cnt;
        }
        if (cnt == mid) return 1;
      }
      return 0;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}