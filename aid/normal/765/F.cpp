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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5, maxq = (int) 3e5 + 5;
int n, q;
int a[maxn];
int ql[maxq], qr[maxq];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &ql[i], &qr[i]);
    ql[i]--;
  }
  return true;
}

int res[maxq];
vector<int> qs[maxn];

int st[2][4 * maxn];

void buildst(int t, int v, int tl, int tr) {
  st[t][v] = inf;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(t, 2 * v, tl, tm);
  buildst(t, 2 * v + 1, tm, tr);
}

void update(int t, int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[t][v] = min(st[t][v], val);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(t, 2 * v, tl, tm, pos, val);
  } else {
    update(t, 2 * v + 1, tm, tr, pos, val);
  }
  st[t][v] = min(st[t][2 * v], st[t][2 * v + 1]);
}

int get(int t, int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[t][v];
  }
  int tm = (tl + tr) / 2;
  int res = inf;
  if (l < tm) {
    res = min(res, get(t, 2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = min(res, get(t, 2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

void solve1() {
  vector<int> xs;
  for (int i = 0; i < n; i++) {
    xs.push_back(a[i]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
  }
  buildst(0, 1, 0, sz(xs));
  buildst(1, 1, 0, n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < sz(qs[i]); j++) {
      int id = qs[i][j];
      res[id] = min(res[id], get(1, 1, 0, n, ql[id], qr[id]));
    }
    if (i == n) {
      break;
    }
    int x = 0;
    while (x <= a[i]) {
      int pos = -get(0, 1, 0, sz(xs), x, a[i] + 1);
      if (pos == -inf) {
        break;
      }
      update(1, 1, 0, n, pos, xs[a[i]] - xs[a[pos]]);
      if (a[i] == a[pos]) {
        break;
      }
      int rx = (xs[a[pos]] + xs[a[i]] + 1) / 2;
      x = lower_bound(xs.begin(), xs.end(), rx) - xs.begin();
    }
    update(0, 1, 0, sz(xs), a[i], -i);
  }
  for (int i = 0; i < n; i++) {
    a[i] = xs[a[i]];
  }
}

void solve() {
  for (int i = 0; i <= n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    res[i] = inf;
    qs[qr[i]].push_back(i);
  }
  solve1();
  for (int i = 0; i < n; i++) {
    a[i] *= -1;
  }
  solve1();
  for (int i = 0; i < q; i++) {
    printf("%d\n", res[i]);
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