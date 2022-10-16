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

const int maxn = (int) 1e5 + 5, maxd = 10;
int n, q;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

struct node {
  long long a[maxd];
  int f[maxd];

  node() {}

  node(int x) {
    for (int i = 0; i < maxd; i++) {
      a[i] = 0;
      f[i] = i;
    }
    long long p = 1;
    while (x) {
      a[x % 10] += p;
      x /= 10;
      p *= 10;
    }
  }

  node(const node &l, const node &r) {
    for (int i = 0; i < maxd; i++) {
      a[i] = l.a[i] + r.a[i];
      f[i] = i;
    }
  }

  void update(int x, int y) {
    long long val = a[x];
    a[x] = 0;
    a[y] += val;
    for (int i = 0; i < maxd; i++) {
      if (f[i] == x) {
        f[i] = y;
      }
    }
  }

  long long get() const {
    long long res = 0;
    for (int i = 0; i < maxd; i++) {
      res += a[i] * i;
    }
    return res;
  }
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v] = node(a[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v] = node(st[2 * v], st[2 * v + 1]);
}

void push(int v) {
  auto &cur = st[v];
  {
    bool ok = true;
    for (int i = 0; i < maxd; i++) {
      if (cur.f[i] != i) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return;
    }
  }
  for (int it = 0; it < 2; it++) {
    auto &nxt = st[2 * v + it];
    static long long a[maxd];
    for (int i = 0; i < maxd; i++) {
      a[i] = 0;
    }
    for (int i = 0; i < maxd; i++) {
      a[cur.f[i]] += nxt.a[i];
      nxt.f[i] = cur.f[nxt.f[i]];
    }
    for (int i = 0; i < maxd; i++) {
      nxt.a[i] = a[i];
    }
  }
  for (int i = 0; i < maxd; i++) {
    cur.f[i] = i;
  }
}

void update(int v, int tl, int tr, int l, int r, int x, int y) {
  if (l == tl && r == tr) {
    st[v].update(x, y);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), x, y);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, x, y);
  }
  st[v] = node(st[2 * v], st[2 * v + 1]);
}

long long get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].get();
  }
  push(v);
  int tm = (tl + tr) / 2;
  long long res = 0;
  if (l < tm) {
    res += get(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += get(2 * v + 1, tm, tr, max(l, tm), r);
  }
  return res;
}

void solve() {
  buildst(1, 0, n);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x, y;
      scanf("%d%d%d%d", &l, &r, &x, &y);
      l--;
      update(1, 0, n, l, r, x, y);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%lld\n", get(1, 0, n, l, r));
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