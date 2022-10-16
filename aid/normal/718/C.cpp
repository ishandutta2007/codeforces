#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct Node {
  int a[2][2], upd[2][2];
  bool needupd;
};

const int maxn = (int) 1e5 + 5, mod = (int) 1e9 + 7;
int n, m;
int ar[maxn], f[2][2];
Node st[4 * maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  return true;
}

int add(int x, int y) {
  int res = x + y;
  if (res >= mod) {
    res -= mod;
  }
  return res;
}

int mul(int x, int y) {
  return (long long)x * y % mod;
}

int c[2][2];

void matMul(int a[2][2], int b[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = c[i][j];
    }
  }
}

int b[2][2];

void matPow(int a[2][2], int p) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      b[i][j] = (i == j);
    }
  }
  while (p) {
    if (p & 1) {
      matMul(b, a);
    }
    p >>= 1;
    matMul(a, a);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = b[i][j];
    }
  }
}

void buildst(int v, int tl, int tr) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[v].upd[i][j] = (i == j);
    }
  }
  st[v].needupd = false;
  if (tl == tr - 1) {
    st[v].a[0][0] = 1;
    st[v].a[0][1] = 1;
    st[v].a[1][0] = 1;
    st[v].a[1][1] = 0;
    matPow(st[v].a, ar[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[v].a[i][j] = add(st[2 * v].a[i][j], st[2 * v + 1].a[i][j]);
    }
  }
}

void push(int v) {
  if (!st[v].needupd) {
    return;
  }
  matMul(st[2 * v].a, st[v].upd);
  matMul(st[2 * v].upd, st[v].upd);
  st[2 * v].needupd = true;
  matMul(st[2 * v + 1].a, st[v].upd);
  matMul(st[2 * v + 1].upd, st[v].upd);
  st[2 * v + 1].needupd = true;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[v].upd[i][j] = (i == j);
    }
  }
  st[v].needupd = false;
}

void update(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    matMul(st[v].a, f);
    matMul(st[v].upd, f);
    st[v].needupd = true;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[v].a[i][j] = add(st[2 * v].a[i][j], st[2 * v + 1].a[i][j]);
    }
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].a[1][0];
  }
  push(v);
  int tm = (tl + tr) / 2, res = 0;
  if (l < tm) {
    res = add(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = add(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

void solve() {
  buildst(1, 0, n);
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l--;
      f[0][0] = 1;
      f[0][1] = 1;
      f[1][0] = 1;
      f[1][1] = 0;
      matPow(f, x);
      update(1, 0, n, l, r);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%d\n", get(1, 0, n, l, r));
    }
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}