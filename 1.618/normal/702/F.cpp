/*
BULB: 0.5h.
result of thinking: Aided. 
.

start coding: 11:05
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, q;
struct Item {
  int w, v;
  bool operator < (const Item &b) const {
    if (v == b.v)
      return w < b.w;
    return v > b.v;
  }
} a[maxn];

namespace Sgt {
  ll sumw[30][maxn << 2], sumv[30][maxn << 2], mini[30][maxn << 2];
  
  void build(int id, int l, int r) {
    if (l == r) {
      for (int i = 0; i <= 29; i++) {
        if (a[l].w < (1 << i)) {
          sumw[i][id] = a[l].w;
          sumv[i][id] = 1;
          mini[i][id] = inf;
        } else {
          mini[i][id] = a[l].w;
        }
      }
    } else {
      int mid = (l + r) >> 1;
      build(id << 1, l, mid);
      build(id << 1 | 1, mid + 1, r);
      for (int i = 0; i <= 29; i++) {
        sumw[i][id] = sumw[i][id << 1] + sumw[i][id << 1 | 1];
        sumv[i][id] = sumv[i][id << 1] + sumv[i][id << 1 | 1];
        mini[i][id] = min(mini[i][id << 1], 
                          mini[i][id << 1 | 1] + sumw[i][id << 1]);
      }
    }
  }
  
  ll solve(int id, int l, int r, ll &c) {
    if (l == r) {
      if (c >= a[l].w) {
        c -= a[l].w;
        return 1;
      }
      return 0;
    }
    int k = 63 - __builtin_clzll(c);
    if (sumw[k][id] >= (1ll << k) || mini[k][id] <= c) {
      int mid = (l + r) >> 1;
      return solve(id << 1, l, mid, c) + 
             solve(id << 1 | 1, mid + 1, r, c);
    }
    c -= sumw[k][id];
    return sumv[k][id];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].w, &a[i].v);
  }
  sort(a + 1, a + n + 1);
  Sgt::build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    ll b;
    scanf("%lld", &b);
    printf("%lld ", Sgt::solve(1, 1, n, b));
  }
  return 0;
}