#include <bits/stdc++.h> 

using namespace std;

int n, k, p[100010];
long long a[100010], b[100010];

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  k = n / 2 + 1;
  long long asum = 0, bsum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    asum += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", b + i);
    bsum += b[i];
  }
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
  while (true) {
    random_shuffle(p + 1, p + n + 1);
    long long anow = 0, bnow = 0;
    for (int i = 1; i <= k; ++i) {
      anow += a[p[i]], bnow += b[p[i]];
    }
    if (anow + anow > asum and bnow + bnow > bsum) {
      printf("%d\n", k);
      for (int i = 1; i <= k; ++i) {
        printf("%d ", p[i]);
      }
      puts("");
      return 0;
    }
  }
  return 0;
}