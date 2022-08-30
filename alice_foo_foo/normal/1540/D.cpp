#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int maxN = 123456, MAGIC = 256;

int mn[MAGIC << 2], tag[MAGIC << 2];
int a[maxN], l[maxN], r[maxN], b[maxN], v[maxN / MAGIC][MAGIC + 1], len[maxN / MAGIC];
int n, q;

int seq[MAGIC];

void update(int u) {
  mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
}

void build(int u, int l, int r) {
  tag[u] = 0;
  if (l == r) {
    mn[u] = seq[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  update(u);
}

int val;
void query(int u, int l, int r, int sum) {
  if (l == r) {
    val = mn[u] + sum;
    mn[u] = 1e9;
    return;
  }
  int mid = (l + r) >> 1;
  if (mn[u << 1] < mn[u << 1 | 1]) {
    query(u << 1, l, mid, sum + tag[u]);
  } else {
    --tag[u << 1]; --mn[u << 1];
    query(u << 1 | 1, mid + 1, r, sum + tag[u]);
  }
  mn[u] = min(mn[u << 1], mn[u << 1 | 1]) + tag[u];
}

void rebuild(int B) {
  int len = 0;
  for (int i = l[B]; i <= r[B]; i++) seq[len++] = a[i];
  build(1, 0, len - 1);
  for (int i = 1; i <= len; i++) {
    query(1, 0, len - 1, 0);
    v[B][i] = max(v[B][i - 1], val);
    // fprintf(stderr, "v[%d][%d] = %d\n", B, i, v[B][i]);
  }
  ::len[B] = len;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] = i - a[i] + 1;
    b[i] = i / MAGIC;
    if (!l[b[i]]) l[b[i]] = i;
    r[b[i]] = i;
  }
  l[0] = 0;
  reverse(a, a + n);
  // for (int i = 0; i < n; i++) fprintf(stderr, "a[%d] = %d\n", i, a[i]);
  for (int i = 0; i <= b[n - 1]; i++) rebuild(i);
  scanf("%d", &q);
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      y = x - 1 - y; x = n - x;
      a[x] = y + 1;
      rebuild(b[x]);
    }
    if (opt == 2) {
      int x;
      scanf("%d", &x);
      x = n - x;
      int r = a[x];
      for (int i = x - 1; i >= l[b[x]]; i--) {
        if (a[i] <= r) ++r;
      }
      for (int i = b[x] - 1; i >= 0; i--) {
        int pos = upper_bound(v[i], v[i] + len[i] + 1, r) - v[i];
        r += pos - 1;
      }
      printf("%d\n", r);
    }
  }
  return 0;
}