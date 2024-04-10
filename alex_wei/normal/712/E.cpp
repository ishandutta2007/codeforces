#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 1e5 + 5;
struct dat {
  double prod, sum;
  dat operator + (const dat &rhs) const {
    dat res;
    res.prod = prod * rhs.prod;
    res.sum = sum + prod * rhs.sum;
    return res;
  }
} val[N << 2];
void modify(int l, int r, int p, int x, double v) {
  if(l == r) return val[x] = {v, v}, void();
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, x << 1, v);
  else modify(m + 1, r, p, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  dat ans = {1, 0};
  if(ql <= m) ans = query(l, m, ql, qr, x << 1);
  if(m < qr) ans = ans + query(m + 1, r, ql, qr, x << 1 | 1);
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    double p = 1. * a / b;
    modify(1, n, i, 1, (1 - p) / p);
  }
  for(int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if(op == 1) {
      int x, a, b;
      scanf("%d%d%d", &x, &a, &b);
      double p = 1. * a / b;
      modify(1, n, x, 1, (1 - p) / p);
    }
    if(op == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%.9lf\n", 1. / (query(1, n, l, r, 1).sum + 1));
    }
  }
  return 0;
}
/*
2022/6/16
start coding at 14:24
finish debugging at 14:35
*/