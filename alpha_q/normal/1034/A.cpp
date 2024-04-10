#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int M = 300010;
const int N = 15000010;

int n, a[M], g, sp[N], cnt[N];

int main() {
  for (int i = 2; i * i < N; ++i) {
    if (sp[i]) continue;
    sp[i] = i;
    for (int j = i * i; j < N; j += i) {
      if (sp[j]) continue;
      sp[j] = i;
    }
  }
  for (int i = 2; i < N; ++i) {
    if (!sp[i]) sp[i] = i;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    g = __gcd(g, a[i]);
  }
  int bad = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] /= g;
    if (a[i] > 1) bad = 0;
    while (a[i] > 1) {
      int p = sp[a[i]];
      while (a[i] % p == 0) {
        a[i] /= p;
      }
      ++cnt[p];
    }
  }
  if (bad) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  for (int i = 2; i < N; ++i) {
    ans = max(ans, cnt[i]);
  }
  printf("%d\n", n - ans);
  return 0;
}