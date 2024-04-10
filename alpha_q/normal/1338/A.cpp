#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int t, n; ll a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i] >= a[i - 1]) continue;
      long long diff = a[i - 1] - a[i], j = 62;
      while (~diff & 1LL << j) --j;
      ans = max(ans, j + 1), a[i] = a[i - 1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}