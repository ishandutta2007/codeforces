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

const int mod[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
  static const int n = 2;
  int a[n];

  Hash() {
    for (int i = 0; i < n; ++i) {
      a[i] = 0;
    }
  }
  
  Hash(int x) {
    for (int i = 0; i < n; ++i) {
      a[i] = x % mod[i];
    }
  }

  Hash operator + (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = a[i] + h.a[i];
      if (res.a[i] >= mod[i]) {
        res.a[i] -= mod[i];
      }
    }
    return res;
  }

  Hash operator - (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = a[i] - h.a[i];
      if (res.a[i] < 0) {
        res.a[i] += mod[i];
      }
    }
    return res;
  }

  Hash operator * (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; ++i) {
      res.a[i] = (long long) a[i] * h.a[i] % mod[i];
    }
    return res;
  }

  bool operator == (const Hash &h) const {
    for (int i = 0; i < n; ++i) {
      if (a[i] != h.a[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator != (const Hash &h) const {
    for (int i = 0; i < n; ++i) {
      if (a[i] != h.a[i]) {
        return true;
      }
    }
    return false;
  }
};

const int maxn = (int) 6e5 + 5;
Hash pws[maxn];

struct T {
  Hash h;
  int len;

  T(): h(), len(0) {}

  T(int x): h(x), len(1) {}

  T(const Hash &h, int len): h(h), len(len) {}

  T operator + (const T &t) const {
    return T(h * pws[t.len] + t.h, len + t.len);
  }

  bool operator == (const T &t) const {
    return h == t.h && len == t.len;
  }

  bool operator != (const T &t) const {
    return h != t.h || len != t.len;
  }
};

void precalc() {
  pws[0] = Hash(1);
  pws[1].a[0] = rnd(mod[0]);
  pws[1].a[1] = rnd(mod[1]);
  for (int i = 2; i < maxn; ++i) {
    pws[i] = pws[i - 1] * pws[1];
  }
}

int n, q;
int a[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

const int logn = 20;
int ps[maxn][logn];
int ls[maxn], rs[maxn];
vector<int> p;

void dfs(int v, int pr) {
  ps[v][0] = (pr == -1 ? v : pr);
  for (int i = 1; i < logn; ++i) {
    ps[v][i] = ps[ps[v][i - 1]][i - 1];
  }
  ls[v] = sz(p);
  p.push_back(a[v]);
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == pr) {
      continue;
    }
    dfs(u, v);
  }
  rs[v] = sz(p);
  p.push_back(a[v]);
}

bool anc(int v, int u) {
  return ls[v] <= ls[u] && rs[u] <= rs[v];
}

int getLca(int v, int u) {
  if (anc(v, u)) {
    return v;
  }
  if (anc(u, v)) {
    return u;
  }
  for (int i = logn - 1; i >= 0; --i) {
    if (!anc(ps[v][i], u)) {
      v = ps[v][i];
    }
  }
  return ps[v][0];
}

struct node {
  T val;
  node *l, *r;

  node(const T &val): val(val), l(0), r(0) {}

  node(node *ll, node *rr): val(ll->val + rr->val), l(ll), r(rr) {}
};

node *buildst(int l, int r) {
  if (l == r - 1) {
    return new node(T(0));
  }
  int m = (l + r) / 2;
  node *vl = buildst(l, m);
  node *vr = buildst(m, r);
  return new node(vl, vr);
}

node *update(node *v, int l, int r, int pos, int val) {
  if (l == r - 1) {
    return new node(T(val));
  }
  int m = (l + r) / 2;
  if (pos < m) {
    return new node(update(v->l, l, m, pos, val), v->r);
  } else {
    return new node(v->l, update(v->r, m, r, pos, val));
  }
}

int get(node *v, node *u, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    if (v->val == u->val) {
      return -1;
    }
    if (l == r - 1) {
      return l;
    }
    int m = (l + r) / 2;
    if (v->l->val != u->l->val) {
      return get(v->l, u->l, l, m, l, m);
    } else {
      return get(v->r, u->r, m, r, m, r);
    }
  }
  int tm = (tl + tr) / 2;
  if (l >= tm) {
    return get(v->r, u->r, tm, tr, l, r);
  }
  if (r <= tm) {
    return get(v->l, u->l, tl, tm, l, r);
  }
  int res = get(v->l, u->l, tl, tm, l, tm);
  if (res == -1) {
    res = get(v->r, u->r, tm, tr, tm, r);
  }
  return res;
}

node *st[maxn];

int getRes(int v, int u, int l, int r) {
  if (rs[v] > rs[u]) {
    swap(v, u);
  }
  int ll = rs[v], rr = rs[u];
  return get(st[ll], st[rr], 0, n, l, r);
}

int cnt[maxn];

void solve() {
  p.clear();
  dfs(0, -1);
  st[0] = buildst(0, n);
  for (int i = 0; i < n; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < sz(p); ++i) {
    cnt[p[i]] ^= 1;
    st[i + 1] = update(st[i], 0, n, p[i], cnt[p[i]]);
  }
  for (int qq = 0; qq < q; ++qq) {
    int v, u, l, r;
    scanf("%d%d%d%d", &v, &u, &l, &r);
    --v;
    --u;
    --l;
    int w = getLca(v, u);
    int x = a[w];
    int res = -1;
    if (x < l || x >= r) {
      res = getRes(v, u, l, r);
    } else {
      if (getRes(v, u, x, x + 1) == -1) {
        res = x;
      } else {
        if (l < x) {
          res = getRes(v, u, l, x);
        }
        if (x + 1 < r && res == -1) {
          res = getRes(v, u, x + 1, r);
        }
      }
    }
    if (res >= 0) {
      ++res;
    }
    printf("%d\n", res);
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