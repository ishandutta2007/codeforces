#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n, q;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

struct node {
  long long sum;
  int mx, mn, upd;
  int len;
};

node st[4 * maxn];

void recalcNode(int v) {
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
  st[v].mx = st[2 * v].mx;
  st[v].mn = st[2 * v + 1].mn;
}

void updateNode(int v, int x) {
  st[v].sum = (long long) x * st[v].len;
  st[v].mx = x;
  st[v].mn = x;
  st[v].upd = x;
}

void buildst(int v, int tl, int tr) {
  st[v].upd = -1;
  st[v].len = tr - tl;
  if (tl == tr - 1) {
    st[v].sum = a[tl];
    st[v].mx = a[tl];
    st[v].mn = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  recalcNode(v);
}

void push(int v) {
  if (st[v].upd == -1) {
    return;
  }
  for (int i = 0; i < 2; ++i) {
    int u = 2 * v + i;
    updateNode(u, st[v].upd);
  }
  st[v].upd = -1;
}

void update(int v, int tl, int tr, int i, int x) {
  if (tr <= i && st[v].mx < x) {
    updateNode(v, x);
    return;
  }
  if (st[v].mn >= x) {
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (i < tm) {
    update(2 * v, tl, tm, i, x);
    recalcNode(v);
    return;
  }
  if (st[2 * v].mn < x) {
    update(2 * v, tl, tm, i, x);
  }
  if (i == tm) {
    recalcNode(v);
    return;
  }
  if (i < tr) {
    update(2 * v + 1, tm, tr, i, x);
    recalcNode(v);
    return;
  }
  if (st[2 * v + 1].mn < x) {
    update(2 * v + 1, tm, tr, i, x);
  }
  recalcNode(v);
}

int getPos(int v, int tl, int tr, long long sum) {
  if (st[v].sum <= sum) {
    return tr;
  }
  if (tl == tr - 1) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (st[2 * v].sum > sum) {
    return getPos(2 * v, tl, tm, sum);
  }
  sum -= st[2 * v].sum;
  return getPos(2 * v + 1, tm, tr, sum);
}

long long getSum(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].sum;
  }
  push(v);
  int tm = (tl + tr) / 2;
  long long res = 0;
  if (l < tm) {
    res += getSum(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += getSum(2 * v + 1, tm, tr, max(l, tm), r);
  }
  return res;
}

int getNext(int v, int tl, int tr, int x) {
  if (st[v].mn > x) {
    return tr;
  }
  if (tl == tr - 1) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (st[2 * v].mn <= x) {
    return getNext(2 * v, tl, tm, x);
  }
  return getNext(2 * v + 1, tm, tr, x);
}

int getFood(int &i, int &x) {
  long long all = (i ? getSum(1, 0, n, 0, i) : 0) + x;
  int j = getPos(1, 0, n, all);
  if (i < j) {
    x -= getSum(1, 0, n, i, j);
  }
  int res = j - i;
  i = j;
  return res;
}

void solve() {
  buildst(1, 0, n);
  for (int qq = 0; qq < q; ++qq) {
    int t, i, x;
    scanf("%d%d%d", &t, &i, &x);
    if (t == 1) {
      update(1, 0, n, i, x);
    } else {
      --i;
      int res = 0;
      while (i < n) {
        res += getFood(i, x);
        if (i >= n) {
          break;
        }
        i = getNext(1, 0, n, x);
      }
      printf("%d\n", res);
    }
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}