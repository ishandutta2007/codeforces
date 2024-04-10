#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n; long long r, x[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %lld", &n, &r);
    long long ans = 0, shift = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", x + i);
    sort(x + 1, x + n + 1);
    for (int i = n; i > 0;) {
      if (x[i] <= shift) break;
      int j = i;
      while (j > 0 and x[j] == x[i]) --j;
      ++ans, shift += r, i = j;
    }
    printf("%lld\n", ans);
  }
  return 0;
}