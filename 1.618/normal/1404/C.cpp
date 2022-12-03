/*


Q.E.D.
*/
/*
start thinking:
BULB:
result of thinking:

start coding:
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

#define maxn 300005
#define mp make_pair
const int inf = 0x3f3f3f3f;
typedef pair<int, int> P;
int n, q, a[maxn];

namespace Sgt {
  int add[maxn << 2], mini[maxn << 2], minId[maxn << 2];
  
  void up(int id) {
    if (mini[id << 1] < mini[id << 1 | 1])
      minId[id] = minId[id << 1];
    else
      minId[id] = minId[id << 1 | 1];
    mini[id] = min(mini[id << 1], mini[id << 1 | 1]) + add[id];
  }
  
  void down(int id) {
    if (add[id]) {
      add[id << 1] += add[id];
      mini[id << 1] += add[id];
      add[id << 1 | 1] += add[id];
      mini[id << 1 | 1] += add[id];
      add[id] = 0;
    }
  }
  
  void build(int id, int l, int r) {
    if (l == r) {
      mini[id] = a[l];
      minId[id] = l;
    } else {
      int mid = (l + r) >> 1;
      build(id << 1, l, mid);
      build(id << 1 | 1, mid + 1, r);
      up(id);
    }
  }
  
  void inc(int id, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
      add[id] += x;
      mini[id] += x;
    } else {
      down(id);
      int mid = (l + r) >> 1;
      if (ql <= mid)  
        inc(id << 1, l, mid, ql, qr, x);
      if (mid < qr)
        inc(id << 1 | 1, mid + 1, r, ql, qr, x);
      up(id);
    }
  }
  
  P qminId(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return mp(mini[id], minId[id]);
    down(id);
    int mid = (l + r) >> 1;
    if (ql > mid)
      return qminId(id << 1 | 1, mid + 1, r, ql, qr);
    if (qr <= mid)
      return qminId(id << 1, l, mid, ql, qr);
    P lans = qminId(id << 1, l, mid, ql, qr),
      rans = qminId(id << 1 | 1, mid + 1, r, ql, qr);
    return lans.first < rans.first ? lans : rans;
  }
}

namespace BIT {
  int bit[maxn];
  void add(int pos, int x) {
    for (int i = pos; i <= n; i += i & -i)
      bit[i] += x;
  }
  int qsum(int pos) {
    int res = 0;
    for (int i = pos; i; i -= i & -i)
      res += bit[i];
    return res;
  }
}

struct Query {
  int l, r, id;
  bool operator < (const Query &q) const {
    return mp(l, r) > mp(q.l, q.r);
  }
} qs[maxn];
int ans[maxn];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] = i - a[i];
    if (a[i] < 0)
      a[i] = inf;
  }
  Sgt::build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qs[i].l, &qs[i].r);
    qs[i].id = i;
  }
  sort(qs + 1, qs + q + 1);
  int lst = n;
  for (int i = 1; i <= q; i++) {
    while (lst > qs[i].l) {
      if (!a[lst]) {
        if (lst < n) {
          Sgt::inc(1, 1, n, lst + 1, n, -1);
          while (true) {
            P mini = Sgt::qminId(1, 1, n, lst + 1, n);
            if (mini.first > 0)
              break;
            if (mini.second < n)
              Sgt::inc(1, 1, n, mini.second + 1, n, -1);
            Sgt::inc(1, 1, n, mini.second, mini.second, inf);
            BIT::add(mini.second, 1);
          }
        }
        Sgt::inc(1, 1, n, lst, lst, inf);
        BIT::add(lst, 1);
      }
      lst--;
    }
    ans[qs[i].id] = BIT::qsum(n - qs[i].r);
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}