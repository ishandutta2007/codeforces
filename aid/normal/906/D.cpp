#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> f;
  for (int d = 2; d * d <= n; d++) {
    if (!(n % d)) {
      f.push_back(make_pair(d, 0));
      while (!(n % d)) {
        n /= d;
        f.back().second++;
      }
    }
  }
  if (n > 1) {
    f.push_back(make_pair(n, 1));
  }
  return f;
}

int powMod(int x, int p, int mod) {
  if (!x) {
    return 0;
  }
  int res = 1;
  while (p) {
    if (p & 1) {
      res = (long long) res * x % mod;
    }
    p >>= 1;
    x = (long long) x * x % mod;
  }
  return res;
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
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = (int) 1e5 + 5;
int n, m;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int nxt1[maxn];

int vs;
int x[maxn], p[maxn], k[maxn];
vector<int> g[maxn];
vector<int> invs[maxn];

int buildTree(int m) {
  int v = vs++;
  x[v] = m;
  p[v] = -1;
  k[v] = -1;
  g[v].clear();
  invs[v].clear();
  if (m == 1) {
    return v;
  }
  vector<pair<int, int>> f = factorize(m);
  if (sz(f) == 1) {
    p[v] = f[0].first;
    k[v] = f[0].second;
    int phi = p[v] - 1;
    for (int i = 0; i < k[v] - 1; i++) {
      phi *= p[v];
    }
    g[v].push_back(buildTree(phi));
  } else {
    int cur = 1;
    for (int i = 0; i < sz(f); i++) {
      int x = 1;
      for (int j = 0; j < f[i].second; j++) {
        x *= f[i].first;
      }
      g[v].push_back(buildTree(x));
      invs[v].push_back(inv(cur, x));
      cur *= x;
    }
  }
  return v;
}

int getk(int l, int r, int curk, int mxk) {
  r = min(r, nxt1[l]);
  int x = 1;
  for (int i = r - 1; i >= l; i--) {
    int nx = 1;
    for (int j = 0; j < x; j++) {
      if ((long long) nx * a[i] >= mxk) {
        return mxk;
      }
      nx *= a[i];
    }
    x = nx;
  }
  if ((long long) x * curk >= mxk) {
    return mxk;
  }
  return x * curk;
}

int get(int v, int l, int r) {
  if (x[v] == 1) {
    return 0;
  }
  if (l == r - 1) {
    return a[l] % x[v];
  }
  if (!(a[l] % x[v])) {
    return 0;
  }
  if (p[v] != -1) {
    int cura = a[l] % x[v];
    int curk = 0;
    while (!(cura % p[v])) {
      cura /= p[v];
      curk++;
    }
    if (curk) {
      curk = getk(l + 1, r, curk, k[v]);
    }
    if (curk >= k[v]) {
      return 0;
    }
    int res = powMod(p[v], curk, x[v]);
    int to = get(g[v][0], l + 1, r);
    res = (long long) res * powMod(cura, to, x[v]) % x[v];
    return res;
  } else {
    int mod = 1;
    int res = 0;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      int cur = get(u, l, r);
      int b = ((cur - res) % x[u] + x[u]) % x[u];
      int c = (long long) b * invs[v][i] % x[u];
      res += c * mod;
      mod *= x[u];
    }
    return res;
  }
}

void solve() {
  nxt1[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    nxt1[i] = (a[i] == 1 ? i : nxt1[i + 1]);
  }
  vs = 0;
  int root = buildTree(m);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    printf("%d\n", get(root, l, r));
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