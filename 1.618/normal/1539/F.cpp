/*


Q.E.D.

BULB: 10min.
result of thinking: Pure.

start coding: 22:46
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
const int inf = 0x3f3f3f3f;
int n, ans[maxn];
vector<int> pos[maxn];

namespace Sgt {
  int mini[maxn << 2], maxi[maxn << 2], add[maxn << 2];

  void up(int id) {
    mini[id] = min(mini[id << 1], mini[id << 1 | 1]) + add[id];
    maxi[id] = max(maxi[id << 1], maxi[id << 1 | 1]) + add[id];
  }

  void down(int id) {
    if (add[id]) {
      add[id << 1] += add[id];
      mini[id << 1] += add[id];
      maxi[id << 1] += add[id];
      add[id << 1 | 1] += add[id];
      mini[id << 1 | 1] += add[id];
      maxi[id << 1 | 1] += add[id];
      add[id] = 0;
    }
  }

  void inc(int id, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
      add[id] += x;
      maxi[id] += x;
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

  int qmin(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return mini[id];
    down(id);
    int mid = (l + r) >> 1, res = inf;
    if (ql <= mid)
      chmin(res, qmin(id << 1, l, mid, ql, qr));
    if (mid < qr)
      chmin(res, qmin(id << 1 | 1, mid + 1, r, ql, qr));
    return res;
  }

  int qmax(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return maxi[id];
    down(id);
    int mid = (l + r) >> 1, res = -inf;
    if (ql <= mid)
      chmax(res, qmax(id << 1, l, mid, ql, qr));
    if (mid < qr)
      chmax(res, qmax(id << 1 | 1, mid + 1, r, ql, qr));
    return res;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    pos[a].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    Sgt::inc(1, 0, n, i, n, -1);
  for (int i = 1; i <= n; i++) {
    for (auto j : pos[i]) {
      int val = Sgt::qmin(1, 0, n, j, n) - Sgt::qmax(1, 0, n, 0, j - 1);
      if (val < 0)
        chmax(ans[j], -val / 2);
    }
    for (auto j : pos[i]) {
      Sgt::inc(1, 0, n, j, n, 2);
    }
    for (auto j : pos[i]) {
      int val = Sgt::qmax(1, 0, n, j, n) - Sgt::qmin(1, 0, n, 0, j - 1);
      if (val > 0)
        chmax(ans[j], val - (val + 2) / 2);
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  cerr << "did not RE" << endl;
  return 0;
}