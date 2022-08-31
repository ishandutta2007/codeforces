#include <bits/stdc++.h>
using namespace std;

int a[20];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    long long pw = 1;
    int maxn = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        pw = pw * 2;
      }
      maxn = max(maxn, a[i]);
      sum += a[i];
    }
    printf("%lld\n", maxn * (pw - 1) + sum);
  }
  return 0;
}