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

const int maxn = (int) 3e5 + 5, maxx = (int) 1e6 + 5;
int n, m;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

struct node {
  int val, toadd;
};

node st[4 * maxx];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].toadd = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    st[v].val += x;
    st[v].toadd += x;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
}

int get(int v, int tl, int tr) {
  if (tl == tr - 1) {
    return tl;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (st[2 * v + 1].val < 0) {
    return get(2 * v + 1, tm, tr);
  } else {
    return get(2 * v, tl, tm);
  }
}

void solve() {
  buildst(1, 0, maxx);
  for (int i = 0; i < n; i++) {
    add(1, 0, maxx, 0, a[i] + 1, -1);
  }
  for (int i = 0; i < m; i++) {
    add(1, 0, maxx, 0, b[i] + 1, 1);
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int t, i, x;
    scanf("%d%d%d", &t, &i, &x);
    i--;
    if (t == 1) {
      add(1, 0, maxx, 0, a[i] + 1, 1);
      a[i] = x;
      add(1, 0, maxx, 0, a[i] + 1, -1);
    } else {
      add(1, 0, maxx, 0, b[i] + 1, -1);
      b[i] = x;
      add(1, 0, maxx, 0, b[i] + 1, 1);
    }
    if (st[1].val >= 0) {
      printf("-1\n");
    } else {
      printf("%d\n", get(1, 0, maxx));
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