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

const int maxn = (int) 1e5 + 5;
int m, n;
int a[maxn];

int read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i <= n; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    a[l]++;
    a[r]--;
  }
  return true;
}

int dpl[maxn], dpr[maxn];
int st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[v] = max(st[v], val);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  st[v] = max(st[2 * v], st[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

void solve() {
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  buildst(1, 0, m);
  for (int i = 0; i < n; i++) {
    dpl[i] = get(1, 0, m, 0, a[i] + 1) + 1;
    update(1, 0, m, a[i], dpl[i]);
  }
  buildst(1, 0, m);
  for (int i = n - 1; i >= 0; i--) {
    dpr[i] = get(1, 0, m, 0, a[i] + 1) + 1;
    update(1, 0, m, a[i], dpr[i]);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dpl[i] + dpr[i] - 1);
  }
  printf("%d\n", res);
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