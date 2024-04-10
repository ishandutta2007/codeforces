#include <bits/stdc++.h>
using namespace std;

const int maxN = 123456;

int d[maxN];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    sort(d + 1, d + n + 1);
    long long ans = d[n], sum = 0;
    for (int i = 1; i <= n; i++) {
      ans -= 1ll * d[i] * (i - 1) - sum;
      sum += d[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}