#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;
int n, m, a[300233], b[300233];
int mx[(M + 10) << 2], tg[(M + 10) << 2];

void pd(int p) {
  mx[p << 1] += tg[p];
  tg[p << 1] += tg[p];
  mx[p << 1 | 1] += tg[p];
  tg[p << 1 | 1] += tg[p];
  tg[p] = 0;
}
void Add(int p, int l, int r, int ql, int qr, int v) {
  if (ql == l && qr == r) {
    mx[p] += v;
    tg[p] += v;
    return;
  }
  pd(p);
  int mid = (l + r) >> 1;
  if (qr <= mid) {
    Add(p << 1, l, mid, ql, qr, v);
  } else if (ql > mid) {
    Add(p << 1 | 1, mid + 1, r, ql, qr, v);
  } else {
    Add(p << 1, l, mid, ql, mid, v);
    Add(p << 1 | 1, mid + 1, r, mid + 1, qr, v);
  }
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}

int Find(int p, int l, int r) {
  if (l == r) {
    return mx[p] > 0 ? l : l - 1;
  }
  pd(p);
  int mid = (l + r) >> 1;
  if (mx[p << 1 | 1] > 0) {
    return Find(p << 1 | 1, mid + 1, r);
  } else {
    return Find(p << 1, l, mid);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    Add(1, 1, M, 1, a[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    Add(1, 1, M, 1, b[i], -1);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int o, x, y;
    scanf("%d%d%d", &o, &x, &y);
    if (o == 1) {
      Add(1, 1, M, 1, a[x], -1);
      a[x] = y;
      Add(1, 1, M, 1, a[x], 1);
    } else {
      Add(1, 1, M, 1, b[x], 1);
      b[x] = y;
      Add(1, 1, M, 1, b[x], -1);
    }
    int w = Find(1, 1, M);
    printf("%d\n", w ? w : -1);
  }
}