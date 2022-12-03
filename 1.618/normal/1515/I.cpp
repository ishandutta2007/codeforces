//  CF702F.
// WA:  31 - __builtin_clz(0). 
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
const ll infll = 0x3f3f3f3f3f3f3f3f;

int n, q, newId[maxn];
struct Item {
  int w, v, cnt, id;
  bool operator < (const Item &b) const {
    if (v == b.v)
      return w < b.w;
    return v > b.v;
  }
} a[maxn];

namespace Sgt {
  ll sumw[18][maxn << 2], sumv[18][maxn << 2], mini[18][maxn << 2];
  
  void build(int id, int l, int r) {
    if (l == r) {
      for (int i = 0; i <= 17; i++) {
        if (a[l].w < (1 << i)) {
          sumw[i][id] = (ll)a[l].cnt * a[l].w;
          sumv[i][id] = (ll)a[l].cnt * a[l].v;
          mini[i][id] = infll;
        } else {
          mini[i][id] = a[l].cnt ? a[l].w : infll;
        }
      }
    } else {
      int mid = (l + r) >> 1;
      build(id << 1, l, mid);
      build(id << 1 | 1, mid + 1, r);
      for (int i = 0; i <= 17; i++) {
        sumw[i][id] = sumw[i][id << 1] + sumw[i][id << 1 | 1];
        sumv[i][id] = sumv[i][id << 1] + sumv[i][id << 1 | 1];
        mini[i][id] = min(mini[i][id << 1], mini[i][id << 1 | 1]
                                            + sumw[i][id << 1]);
      }
    }
  }
  
  void add(int id, int l, int r, int pos, int x) {
    if (l == r) {
      for (int i = 0; i <= 17; i++) {
        if (a[l].w < (1 << i)) {
          sumw[i][id] += (ll)x * a[l].w;
          sumv[i][id] += (ll)x * a[l].v;
          mini[i][id] = infll;
        } else {
          mini[i][id] = a[l].cnt ? a[l].w : infll;
        }
      }
    } else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        add(id << 1, l, mid, pos, x);
      else
        add(id << 1 | 1, mid + 1, r, pos, x);
      for (int i = 0; i <= 17; i++) {
        sumw[i][id] = sumw[i][id << 1] + sumw[i][id << 1 | 1];
        sumv[i][id] = sumv[i][id << 1] + sumv[i][id << 1 | 1];
        mini[i][id] = min(mini[i][id << 1], mini[i][id << 1 | 1]
                                            + sumw[i][id << 1]);
      }
    }
  }
  
  ll solve(int id, int l, int r, ll &c) {
    if (!c)
      return 0;
    if (l == r) {
      int num = min((ll)a[l].cnt, c / a[l].w);
      c -= (ll)num * a[l].w;
      return (ll)num * a[l].v;
    }
    int k = min(63 - __builtin_clzll(c), 17);
    if (sumw[k][id] > c || mini[k][id] <= c) {
      int mid = (l + r) >> 1;
      return solve(id << 1, l, mid, c)
             + solve(id << 1 | 1, mid + 1, r, c);
    }
    c -= sumw[k][id];
    return sumv[k][id];
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].cnt, &a[i].w, &a[i].v);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    newId[a[i].id] = i;
  Sgt::build(1, 1, n);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int k, d;
      scanf("%d%d", &k, &d);
      a[newId[d]].cnt += k;
      Sgt::add(1, 1, n, newId[d], k);
    } else if (t == 2) {
      int k, d;
      scanf("%d%d", &k, &d);
      a[newId[d]].cnt -= k;
      Sgt::add(1, 1, n, newId[d], -k);
    } else {
      ll c;
      scanf("%lld", &c);
      printf("%lld\n", Sgt::solve(1, 1, n, c));
    }
  }
  return 0;
}