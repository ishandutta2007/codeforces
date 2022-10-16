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

const int maxn = (int) 4e5 + 5;
int f[maxn], inv[maxn], finv[maxn];

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int n, m;
int x[maxn], y[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i];
    --y[i];
  }
  return true;
}

struct node {
  node *l, *r;
  int x, y;
  int toadd;

  node(int x): l(0), r(0), x(x), y(mrand()), toadd(0) {}

  void push() {
    if (!toadd) {
      return;
    }
    if (l) {
      l->x += toadd;
      l->toadd += toadd;
    }
    if (r) {
      r->x += toadd;
      r->toadd += toadd;
    }
    toadd = 0;
  }
};

node *merge(node *l, node *r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  if (l->y < r->y) {
    l->push();
    l->r = merge(l->r, r);
    return l;
  } else {
    r->push();
    r->l = merge(l, r->l);
    return r;
  }
}

void split(node *v, int x, node *&l, node *&r) {
  if (!v) {
    l = 0;
    r = 0;
    return;
  }
  v->push();
  if (v->x < x) {
    split(v->r, x, v->r, r);
    l = v;
  } else {
    split(v->l, x, l, v->l);
    r = v;
  }
}

int getCnt(node *v) {
  if (!v) {
    return 0;
  }
  return 1 + getCnt(v->l) + getCnt(v->r);
}

void solve() {
  node *root = 0;
  for (int i = 0; i < m; ++i) {
    int p = y[i];
    node *l, *m, *r;
    split(root, p, l, r);
    split(r, p + 1, m, r);
    if (!m) {
      m = new node(p);
    }
    r = merge(m, r);
    ++r->toadd;
    ++r->x;
    root = merge(l, r);
  }
  int cnt = getCnt(root);
  printf("%d\n", c(n + n - 1 - cnt, n));
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}