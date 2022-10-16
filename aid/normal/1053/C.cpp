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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

#define ws wwwwwwwwwwwwws

const int maxn = (int) 2e5 + 5;
int n, q;
int xs[maxn];
int ws[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &xs[i]);
    xs[i] -= i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ws[i]);
  }
  return true;
}

long long st[4 * maxn];
int stx[4 * maxn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v] = ws[tl];
    stx[v] = mul(ws[tl], xs[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v] = st[2 * v] + st[2 * v + 1];
  stx[v] = stx[2 * v];
  add(stx[v], stx[2 * v + 1]);
}

void update(int v, int tl, int tr, int pos, int nw) {
  if (tl == tr - 1) {
    ws[tl] = nw;
    st[v] = ws[tl];
    stx[v] = mul(ws[tl], xs[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, nw);
  } else {
    update(2 * v + 1, tm, tr, pos, nw);
  }
  st[v] = st[2 * v] + st[2 * v + 1];
  stx[v] = stx[2 * v];
  add(stx[v], stx[2 * v + 1]);
}

long long getSum(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
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

int getSumX(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return stx[v];
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    add(res, getSumX(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    add(res, getSumX(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

int getPos(int v, int tl, int tr, long long s) {
  if (tl == tr - 1) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  if (st[2 * v] >= s) {
    return getPos(2 * v, tl, tm, s);
  } else {
    return getPos(2 * v + 1, tm, tr, s - st[2 * v]);
  }
}

void solve() {
  buildst(1, 0, n);
  for (int qq = 0; qq < q; qq++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      int id = -x, nw = y;
      id--;
      update(1, 0, n, id, nw);
    } else {
      int l = x, r = y;
      l--;
      long long sum = getSum(1, 0, n, l, r);
      long long s2 = (l ? getSum(1, 0, n, 0, l) : 0) + (sum + 1) / 2;
      int pos = getPos(1, 0, n, s2);
      int res = 0;
      if (pos > l) {
        add(res, mul(getSum(1, 0, n, l, pos) % mod, xs[pos]));
        add(res, mod - getSumX(1, 0, n, l, pos));
      }
      add(res, getSumX(1, 0, n, pos, r));
      add(res, mod - mul(getSum(1, 0, n, pos, r) % mod, xs[pos]));
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