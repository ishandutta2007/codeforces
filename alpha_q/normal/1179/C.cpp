#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m, q, a[N], b[N], sum[4 * N], suff[4 * N];

void update (int p, int v, int u = 1, int b = 1, int e = 1000000) {
  if (b > p or e < p) return;
  if (b == e) {sum[u] += v, suff[u] += v; return;}
  int mid = b + e >> 1;
  update(p, v, u + u, b, mid);
  update(p, v, u + u + 1, mid + 1, e);
  sum[u] = sum[u + u] + sum[u + u + 1];
  suff[u] = max(suff[u + u + 1], suff[u + u] + sum[u + u + 1]);
}

int query (int carry = 0, int u = 1, int b = 1, int e = 1000000) {
  if (b == e) return suff[u] + carry > 0 ? b : -1;
  int mid = b + e >> 1;
  if (suff[u + u + 1] + carry > 0) return query(carry, u + u + 1, mid + 1, e);
  return query(carry + sum[u + u + 1], u + u, b, mid);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    update(a[i], +1);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", b + i);
    update(b[i], -1);
  }
  cin >> q;
  while (q--) {
    int cmd, at, x;
    scanf("%d %d %d", &cmd, &at, &x);
    if (cmd == 1) {
      update(a[at], -1);
      a[at] = x;
      update(a[at], +1);
    } else {
      update(b[at], +1);
      b[at] = x;
      update(b[at], -1);
    }
    printf("%d\n", query());
  }
  return 0;
}