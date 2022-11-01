#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, q, m, a[N];
int cmd[N], l[N], r[N];

int main() {
  scanf("%d %d %d", &n, &q, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d %d", cmd + i, l + i, r + i);
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = q; j; --j) {
      if (x < l[j] or x > r[j]) continue;
      if (cmd[j] == 1) {
        if (x == l[j]) x = r[j];
        else --x;
      } else {
        x = l[j] + r[j] - x;
      }
    }
    printf("%d ", a[x]);
  }
  puts("");
  return 0;
}