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

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int inv100 = inv(100);

const int maxn = (int) 2e5 + 5;
int n, q;
int p[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i] = mul(p[i], inv100);
  }
  return true;
}

int st[4 * maxn][3];

void calc(int x[3], int y[3], int z[3]) {
  int tomul = y[1];
  x[0] = y[0];
  add(x[0], mul(z[0], tomul));
  x[1] = mul(z[1], tomul);
  x[2] = y[2];
  add(x[2], mul(z[2], tomul));
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v][0] = 1;
    st[v][1] = p[tl];
    st[v][2] = 1;
    add(st[v][2], mod - p[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  calc(st[v], st[2 * v], st[2 * v + 1]);
}

void get(int v, int tl, int tr, int l, int r, int x[3]) {
  if (l == tl && r == tr) {
    int nx[3];
    calc(nx, st[v], x);
    for (int i = 0; i < 3; i++) {
      x[i] = nx[i];
    }
    return;
  }
  int tm = (tl + tr) / 2;
  if (r > tm) {
    get(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  if (l < tm) {
    get(2 * v, tl, tm, l, min(r, tm), x);
  }
}

int solveSeg(int l, int r) {
  int x[3] = {0, 0, 0};
  get(1, 0, n, l, r, x);
  int todiv = 1;
  add(todiv, mod - x[2]);
  return mul(x[0], inv(todiv));
}

set<int> cp;

void solve() {
  buildst(1, 0, n);
  cp.clear();
  cp.insert(0);
  cp.insert(n);
  int res = solveSeg(0, n);
  for (int qq = 0; qq < q; qq++) {
    int i;
    scanf("%d", &i);
    i--;
    if (cp.count(i)) {
      auto it = cp.find(i);
      auto lit = it, rit = it;
      lit--;
      rit++;
      add(res, mod - solveSeg(*lit, i));
      add(res, mod - solveSeg(i, *rit));
      add(res, solveSeg(*lit, *rit));
      cp.erase(it);
    } else {
      auto rit = cp.lower_bound(i);
      auto lit = rit;
      lit--;
      add(res, mod - solveSeg(*lit, *rit));
      add(res, solveSeg(*lit, i));
      add(res, solveSeg(i, *rit));
      cp.insert(rit, i);
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