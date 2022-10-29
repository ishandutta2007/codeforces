#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool vmax(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}

#define ll long long

const int N = 2e5 + 5;

int n, m;
int sa, sb;
int a[N], b[N];
int bh[N], bv[N];

int calc_difx(int x, int y, bool flg = false) {
  return y + bv[x] - m + (flg && x == sa && sb > y);
}

int calc_dify(int x, int y, bool flg = false) {
  return x + bh[y] - n + (flg && y == sb && sa > x);
}

bool check(int mid) {
  for (int i = 1, j = m; i <= n; i++) {
    while (j && a[i] + b[j] > mid) j--;
    bv[i] = j;
  }
  for (int i = 1, j = n; i <= m; i++) {
    while (j && a[j] + b[i] > mid) j--;
    bh[i] = j;
  }
  ll res0 = 0, res1;
  for (int i = 1; i <= n; i++) {
    res0 += m - bv[i];
  }
  res1 = res0;
  ll tmp = res1;
  for (int y = 1, x = 0; y <= m; y++) {
    tmp += calc_dify(x, y);
    while (x < n && calc_difx(x + 1, y) > 0)
      tmp += calc_difx(++x, y);
    vmax(res1, tmp);
  }
  tmp = --res0;
  for (int y = 1, x = 0; y <= m; y++) {
    tmp += calc_dify(x, y, true);
    while (x < n && calc_difx(x + 1, y, true) > 0)
      tmp += calc_difx(++x, y, true);
    if (x == sa && x < n && !calc_difx(x + 1, y, true))
      tmp += calc_difx(++x, y, true);
    while (x < n && calc_difx(x + 1, y, true) > 0)
      tmp += calc_difx(++x, y, true);
    vmax(res0, tmp);
  }
//  cerr << res0 << " " << res1 << '\n';
  return res0 == res1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
  }
  sa = a[1], sb = b[1];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int l = 2, r = sa + sb - 1, mid;
  for (int i = 1; i <= n; i++) {
    if (sa == a[i]) {
      sa = i;
      break;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (sb == b[i]) {
      sb = i;
      break;
    }
  }
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", r + 1);
  return 0;
}