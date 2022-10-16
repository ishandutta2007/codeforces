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

const int mod = (int) 1e9 + 7;

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

const int maxn = 6;
int n;
int ps[maxn][maxn];
int qs[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &ps[i][j]);
    }
  }
  return true;
}

const int pown = (1 << maxn);
int ids[pown];
vector<int> msks;
vector<pair<int, int>> es;
vector<int> a, b;
int can[maxn][maxn];

void genMsk(int i, int k, int cur, bool inv, int &msk) {
  if (i >= k) {
    if (inv) {
      cur = (((1 << n) - 1) ^ cur);
    }
    assert(ids[cur] != -1);
    msk |= (1 << ids[cur]);
    return;
  }
  for (int j = 0; j < n; j++) {
    if (!can[i][j] || (cur & (1 << j))) {
      continue;
    }
    genMsk(i + 1, k, (cur | (1 << j)), inv, msk);
  }
}

void solve() {
  {
    int tomul = inv(100);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ps[i][j] = mul(ps[i][j], tomul);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        qs[i][j] = 1;
        add(qs[i][j], mod - ps[i][j]);
      }
    }
  }
  int k = n / 2;
  {
    msks.clear();
    for (int i = 0; i < (1 << n); i++) {
      ids[i] = -1;
      if (__builtin_popcount(i) == k) {
        ids[i] = sz(msks);
        msks.push_back(i);
      }
    }
  }
  es.clear();
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      es.push_back(make_pair(i, j));
    }
  }
  a.clear();
  a.resize(1 << sz(msks));
  for (int i = 0; i < (1 << sz(es)); i++) {
    int p = 1, msk = 0;
    for (int j = 0; j < sz(es); j++) {
      int v = es[j].first, u = es[j].second;
      can[v][u] = false;
      if (i & (1 << j)) {
        can[v][u] = true;
        p = mul(p, ps[v][u]);
      } else {
        p = mul(p, qs[v][u]);
      }
    }
    genMsk(0, k, 0, false, msk);
    add(a[msk], p);
  }
  es.clear();
  for (int i = k; i < n; i++) {
    for (int j = 0; j < n; j++) {
      es.push_back(make_pair(i, j));
    }
  }
  b.clear();
  b.resize(1 << sz(msks));
  for (int i = 0; i < (1 << sz(es)); i++) {
    int p = 1, msk = 0;
    for (int j = 0; j < sz(es); j++) {
      int v = es[j].first, u = es[j].second;
      can[v][u] = false;
      if (i & (1 << j)) {
        can[v][u] = true;
        p = mul(p, ps[v][u]);
      } else {
        p = mul(p, qs[v][u]);
      }
    }
    genMsk(k, n, 0, true, msk);
    add(b[msk], p);
  }
  for (int j = 0; j < sz(msks); j++) {
    for (int i = 0; i < (1 << sz(msks)); i++) {
      if (!(i & (1 << j))) {
        add(a[i], a[i | (1 << j)]);
      }
    }
  }
  for (int j = 0; j < sz(msks); j++) {
    for (int i = 0; i < (1 << sz(msks)); i++) {
      if (!(i & (1 << j))) {
        add(b[i], b[i | (1 << j)]);
      }
    }
  }
  for (int i = 0; i < (1 << sz(msks)); i++) {
    a[i] = mul(a[i], b[i]);
  }
  for (int j = 0; j < sz(msks); j++) {
    for (int i = 0; i < (1 << sz(msks)); i++) {
      if (!(i & (1 << j))) {
        add(a[i], mod - a[i | (1 << j)]);
      }
    }
  }
  int res = 0;
  for (int i = 1; i < (1 << sz(msks)); i++) {
    add(res, a[i]);
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