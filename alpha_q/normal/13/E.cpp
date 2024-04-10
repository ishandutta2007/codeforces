#include <bits/stdc++.h> 

using namespace std;

int SQ;
const int N = 100010;

int n, m, next[N], step[N], a[N], last[N];

bool same (int u, int v) {
  if (max(u, v) == n + 1) return 0;
  return (u - 1)/SQ == (v - 1)/SQ;
}

void update (int i) {
  if (i + a[i] > n) {
    next[i] = n + 1;
    step[i] = 1;
    last[i] = i;
  } else if (same(i, i + a[i])) {
    next[i] = next[i + a[i]];
    step[i] = 1 + step[i + a[i]];
    last[i] = last[i + a[i]];
  } else {
    next[i] = i + a[i];
    step[i] = 1;
    last[i] = i;
  }
}

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  SQ = sqrt(n);
  for (int i = n; i; --i) {
    update(i);
  }
  while (m--) {
    int cmd, x, y;
    scanf("%d %d", &cmd, &x);
    if (cmd) {
      int ans = 0, pre = x;
      for (int i = x; i <= n; i = next[i]) {
        ans += step[i];
        pre = last[i];
      }
      printf("%d %d\n", pre, ans);
    } else {
      scanf("%d", &y);
      a[x] = y;
      for (int i = x; i and same(i, x); --i) {
        update(i);
      }
    }
  }
  return 0;
}