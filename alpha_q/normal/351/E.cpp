#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] = abs(a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = 0;
    for (int j = 1; j < i; ++j) {
      if (a[j] < a[i]) ++l;
    }
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] < a[i]) ++r;
    }
    ans += min(l, r);
  }
  printf("%d\n", ans);
  return 0;
}