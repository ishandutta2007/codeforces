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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int n;
int xs[maxn], ys[maxn], s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &xs[i], &ys[i], &s[i]);
  }
  return true;
}

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

void add(int v, int tl, int tr, int l, int r, int val) {
  if (l == tl && r == tr) {
    add(st[v], val);
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), val);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, val);
  }
}

int get(int v, int tl, int tr, int pos) {
  int res = st[v];
  if (tl == tr - 1) {
    return res;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    add(res, get(2 * v, tl, tm, pos));
  } else {
    add(res, get(2 * v + 1, tm, tr, pos));
  }
  return res;
}

void solve() {
  int res = 1;
  buildst(1, 0, n);
  add(1, 0, n, 0, n, 1);
  for (int i = n - 1; i >= 0; --i) {
    int d = (xs[i] - (i ? xs[i - 1] : 0));
    d %= mod;
    int cnt = get(1, 0, n, i);
    int cnt2 = mul(cnt, 2);
    if (!s[i]) {
      add(cnt2, mod - 1);
      add(cnt, mod - 1);
    }
    add(res, mul(d, cnt2));
    int j = lower_bound(xs, xs + n, ys[i]) - xs;
    if (j < i) {
      add(1, 0, n, j, i, cnt);
    }
    int dd = (ys[i] - (j ? xs[j - 1] : 0));
    add(res, mod - mul(cnt, dd));
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