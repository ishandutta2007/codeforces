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

const int maxn = (int) 1.5e5 + 5;
int n, q;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int ts[maxn];

void dfs0(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v);
    ts[v] += ts[u];
  }
}

vector<pair<int, int>> tosort;
int tin[maxn], tout[maxn], t;
vector<int> ps[maxn], ks[maxn];

void dfs1(int v, int p) {
  tin[v] = t++;
  tosort.clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    tosort.push_back(make_pair(ts[u], u));
  }
  sort(tosort.begin(), tosort.end());
  g[v].clear();
  for (int i = 0; i < sz(tosort); i++) {
    g[v].push_back(tosort[i].second);
  }
  int prv = -1;
  ps[v].clear();
  ks[v].clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (ts[u] != prv) {
      ps[v].push_back(t);
      ks[v].push_back(ts[u]);
      prv = ts[u];
    }
    dfs1(u, v);
  }
  ps[v].push_back(t);
  tout[v] = t;
}

int fen[maxn];

void fenAdd(int i, int x) {
  for (; i <= n; i |= i + 1) {
    add(fen[i], x);
  }
}

void addSeg(int l, int r, int x) {
  fenAdd(l, x);
  fenAdd(r, mod - x);
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    add(res, fen[i]);
  }
  return res;
}

void solve() {
  dfs0(0, -1);
  t = 0;
  dfs1(0, -1);
  for (int i = 0; i <= n; i++) {
    fen[i] = 0;
  }
  int s = 0;
  int invn = inv(n);
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, d;
      scanf("%d%d", &v, &d);
      v--;
      add(s, d);
      d = mul(d, invn);
      d = mul(d, mod - 1);
      for (int i = 0; i < sz(ks[v]); i++) {
        int l = ps[v][i], r = ps[v][i + 1];
        addSeg(l, r, mul(ks[v][i], d));
      }
      {
        int l = tin[v], r = tout[v];
        int k = n - ts[v];
        addSeg(0, l, mul(k, d));
        addSeg(r, n, mul(k, d));
      }
    } else {
      int v;
      scanf("%d", &v);
      v--;
      int res = s;
      add(res, get(tin[v]));
      printf("%d\n", res);
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