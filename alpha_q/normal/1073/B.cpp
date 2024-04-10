#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n, a[N], b[N], p[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    p[a[i]] = i;
  }
  int at = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    int cur = p[b[i]];
    if (cur < at) {
      printf("0 ");
    } else {
      printf("%d ", cur - at + 1);
      at = cur + 1;
    }
  }
  puts("");
  return 0;
}