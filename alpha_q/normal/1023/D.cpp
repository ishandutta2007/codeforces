#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

set <int> pos[N], cur;
int n, q, a[N], t[4 * N], lz[4 * N];

void prop (int u, int b, int e) {
  t[u] = lz[u];
  if (b != e) {
    lz[u + u] = lz[u];
    lz[u + u + 1] = lz[u];
  }
  lz[u] = 0;
}

void update (int l, int r, int v, int u = 1, int b = 1, int e = n) {
  if (lz[u]) prop(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lz[u] = v;
    prop(u, b, e);
    return;
  }
  int m = b + e >> 1;
  update(l, r, v, u + u, b, m);
  update(l, r, v, u + u + 1, m + 1, e);
  t[u] = max(t[u + u], t[u + u + 1]);
}

int query (int p, int u = 1, int b = 1, int e = n) {
  if (b > p or e < p) return 0;
  if (lz[u]) prop(u, b, e);
  if (b == e) return t[u];
  int m = b + e >> 1;
  return query(p, u + u, b, m) + query(p, u + u + 1, m + 1, e);
}

int main() {
  scanf("%d %d", &n, &q);
  int mx = 0, zero = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 0) zero = i;
    else pos[a[i]].insert(i);
    mx = max(mx, a[i]);
  }
  if (zero == 0 and mx != q) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= q; ++i) {
    if (pos[i].empty()) continue;
    int l = *pos[i].begin(), r = *(--pos[i].end());
    auto it = cur.lower_bound(l);
    if (it != cur.end() and *it <= r) {
      puts("NO");
      return 0;
    }
    for (int x : pos[i]) cur.insert(x);
  }
  update(1, n, 1);
  for (int i = 2; i <= mx; ++i) {
    if (pos[i].empty()) continue;
    int l = *pos[i].begin(), r = *(--pos[i].end());
    update(l, r, i);
  }
  if (mx != q) {
    update(zero, zero, q);
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    printf("%d ", query(i));
  }
  puts("");
  return 0; 
}

// 111222222111111111111