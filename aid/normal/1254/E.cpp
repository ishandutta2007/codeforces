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

const int maxn = (int) 5e5 + 5;
int f[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
}

int n;
vector<int> g[maxn];
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
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
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

const int logn = 20;
int pr[maxn][logn];
int q[maxn];
int used[maxn];
int tin[maxn], tout[maxn], t;

void dfs0(int v, int p) {
  tin[v] = t++;
  pr[v][0] = (p == -1 ? v : p);
  for (int i = 1; i < logn; i++) {
    pr[v][i] = pr[pr[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v);
  }
  tout[v] = t;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int get(int v, int u) {
  if (v == u) {
    return v;
  }
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(pr[v][i], u)) {
      v = pr[v][i];
    }
  }
  return v;
}

int ls[maxn], rs[maxn];
int nxt[maxn];
int res;

bool dfs(int v, int pp) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == pp) {
      continue;
    }
    if (!dfs(u, v)) {
      return false;
    }
  }
  auto &l = ls[v];
  auto &r = rs[v];
  l = -1;
  r = -1;
  int lid = -1;
  if (p[v] != -1 && !anc(v, p[v])) {
    r = p[v];
  }
  if (q[v] != -1 && !anc(v, q[v])) {
    l = q[v];
    lid = v;
  }
  nxt[v] = (p[v] == -1 || !anc(v, p[v]) ? p[v] : get(p[v], v));
  int k = 0;
  if (q[v] == -1 || !anc(v, q[v])) {
    k++;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == pp) {
      continue;
    }
    if (ls[u] != -1 && !anc(v, ls[u])) {
      if (l == -1) {
        l = ls[u];
        lid = u;
      }
      if (l != ls[u]) {
        return false;
      }
    }
    if (rs[u] != -1 && !anc(v, rs[u])) {
      if (r == -1) {
        r = rs[u];
      }
      if (r != rs[u]) {
        return false;
      }
    }
    if (ls[u] == -1 || !anc(v, ls[u])) {
      k++;
    }
    nxt[u] = (rs[u] == -1 || !anc(v, rs[u]) ? rs[u] : get(rs[u], v));
  }
  //eprintf("%d %d %d %d\n", v, l, r, k);
  {
    used[v] = false;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == pp) {
        continue;
      }
      used[u] = false;
    }
    if (k == 0) {
      if (pp != -1) {
        return false;
      }
      int w = v;
      while (w != -1 && !used[w] && anc(v, w)) {
        used[w] = true;
        w = nxt[w];
      }
      if (w == -1 || !anc(v, w)) {
        return false;
      }
      if (!used[v]) {
        return false;
      }
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u == pp) {
          continue;
        }
        if (!used[u]) {
          return false;
        }
      }
      return true;
    }
    if (lid != -1) {
      int w = lid;
      while (w != -1 && !used[w] && anc(v, w)) {
        used[w] = true;
        w = nxt[w];
      }
      if (w != -1) {
        if (anc(v, w)) {
          return false;
        }
        if (!used[v]) {
          return false;
        }
        for (int i = 0; i < sz(g[v]); i++) {
          int u = g[v][i];
          if (u == pp) {
            continue;
          }
          if (!used[u]) {
            return false;
          }
        }
        return true;
      }
    }
    if (!used[v] && (q[v] == -1 || !anc(v, q[v]))) {
      int w = v;
      while (w != -1 && !used[w] && anc(v, w)) {
        used[w] = true;
        w = nxt[w];
      }
      if (w != -1 && anc(v, w)) {
        return false;
      }
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == pp) {
        continue;
      }
      if (!used[u] && (ls[u] == -1 || !anc(v, ls[u]))) {
        int w = u;
        while (w != -1 && !used[w] && anc(v, w)) {
          used[w] = true;
          w = nxt[w];
        }
        if (w != -1 && anc(v, w)) {
          return false;
        }
      }
    }
    if (!used[v]) {
      return false;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == pp) {
        continue;
      }
      if (!used[u]) {
        return false;
      }
    }
  }
  if (k == 1) {
    return true;
  }
  if (pp == -1) {
    if (k) {
      k--;
      res = mul(res, f[k]);
    }
    return res;
  }
  if (l != -1) {
    k--;
  }
  if (r != -1) {
    k--;
  }
  res = mul(res, f[k]);
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    q[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) {
      q[p[i]] = i;
    }
  }
  t = 0;
  dfs0(0, -1);
  res = 1;
  if (!dfs(0, -1)) {
    res = 0;
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