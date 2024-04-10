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

int mul(int a, int b, int mod) {
  return (long long) a * b % mod;
}

void add(int &a, int b, int mod) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x, int mod) {
  int res = gcd(x, mod).first;
  return ((res % mod) + mod) % mod;
}

const int maxn = (int) 4e5 + 5;
int n, m, q;
int a[maxn];
int qs[maxn][4];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &qs[i][0]);
    int k = (qs[i][0] == 1 ? 4 : 3);
    for (int j = 1; j < k; j++) {
      scanf("%d", &qs[i][j]);
    }
  }
  return true;
}

int wasm;
int ans[maxn];

int p, k, pk;

struct T {
  int x, q;

  T(): x(1), q(0) {}

  T(int val) {
    x = val;
    q = 0;
    while (!(x % p)) {
      x /= p;
      q++;
    }
    x %= pk;
  }

  T operator * (const T &t) const {
    T res;
    res.x = mul(x, t.x, pk);
    res.q = q + t.q;
    return res;
  }

  T inv() const {
    T res;
    res.x = ::inv(x, pk);
    res.q = -q;
    return res;
  }

  int getVal() const {
    if (q >= k) {
      return 0;
    }
    int res = x;
    for (int i = 0; i < q; i++) {
      res = mul(res, p, pk);
    }
    return res;
  }
};

struct node {
  int val;
  int tomul;
  T t;

  void update(int x, const T &tt) {
    val = mul(val, x, pk);
    tomul = mul(tomul, x, pk);
    t = t * tt;
  }
};

node st[4 * maxn];
T as[maxn];

void buildst(int v, int tl, int tr) {
  st[v].tomul = 1;
  st[v].t = T();
  if (tl == tr - 1) {
    as[tl] = T(a[tl]);
    st[v].val = as[tl].getVal();
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].val = st[2 * v].val;
  add(st[v].val, st[2 * v + 1].val, pk);
}

void push(int v, int tl, int tm, int tr) {
  if (st[v].tomul == 1) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    int nl = (!i ? tl : tm);
    int nr = (!i ? tm : tr);
    st[u].update(st[v].tomul, st[v].t);
    if (nl == nr - 1) {
      as[nl] = as[nl] * st[v].t;
      st[u].val = as[nl].getVal();
    }
  }
  st[v].tomul = 1;
  st[v].t = T();
}

void update(int v, int tl, int tr, int l, int r, int tomul, T t) {
  if (l == tl && r == tr) {
    st[v].update(tomul, t);
    if (tl == tr - 1) {
      as[tl] = as[tl] * t;
      st[v].val = as[tl].getVal();
    }
    return;
  }
  int tm = (tl + tr) / 2;
  push(v, tl, tm, tr);
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), tomul, t);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, tomul, t);
  }
  st[v].val = st[2 * v].val;
  add(st[v].val, st[2 * v + 1].val, pk);
}

void update1(int v, int tl, int tr, int pos, T t) {
  if (tl == tr - 1) {
    as[tl] = as[tl] * t;
    st[v].val = as[tl].getVal();
    return;
  }
  int tm = (tl + tr) / 2;
  push(v, tl, tm, tr);
  if (pos < tm) {
    update1(2 * v, tl, tm, pos, t);
  } else {
    update1(2 * v + 1, tm, tr, pos, t);
  }
  st[v].val = st[2 * v].val;
  add(st[v].val, st[2 * v + 1].val, pk);
}

int getSum(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  int tm = (tl + tr) / 2;
  push(v, tl, tm, tr);
  int res = 0;
  if (l < tm) {
    add(res, getSum(2 * v, tl, tm, l, min(r, tm)), pk);
  }
  if (r > tm) {
    add(res, getSum(2 * v + 1, tm, tr, max(l, tm), r), pk);
  }
  return res;
}

int crt(int a, int n, int b, int m) {
  int k = ((b - a) % m + m) % m;
  k = mul(k, inv(n % m, m), m);
  return k * n + a;
}

void solve() {
  wasm = 1;
  for (int i = 0; i < q; i++) {
    ans[i] = (qs[i][0] == 3 ? 0 : -1);
  }
  vector<pair<int, int>> f;
  {
    int x = m;
    for (int d = 2; d * d <= x; d++) {
      if (!(x % d)) {
        int k = 0;
        while (!(x % d)) {
          x /= d;
          k++;
        }
        f.push_back(make_pair(d, k));
      }
    }
    if (x > 1) {
      f.push_back(make_pair(x, 1));
    }
  }
  for (int it = 0; it < sz(f); it++) {
    p = f[it].first;
    k = f[it].second;
    pk = 1;
    for (int i = 0; i < k; i++) {
      pk *= p;
    }
    buildst(1, 0, n);
    for (int i = 0; i < q; i++) {
      if (qs[i][0] == 1) {
        int l = qs[i][1], r = qs[i][2], x = qs[i][3];
        l--;
        T t(x);
        update(1, 0, n, l, r, x, t);
      } else if (qs[i][0] == 2) {
        int pos = qs[i][1], x = qs[i][2];
        pos--;
        T t = T(x).inv();
        update1(1, 0, n, pos, t);
      } else {
        int l = qs[i][1], r = qs[i][2];
        l--;
        int x = getSum(1, 0, n, l, r);
        eprintf("%d %d\n", x, pk);
        ans[i] = crt(ans[i], wasm, x, pk);
      }
    }
    wasm *= pk;
  }
  for (int i = 0; i < q; i++) {
    if (qs[i][0] == 3) {
      printf("%d\n", ans[i]);
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