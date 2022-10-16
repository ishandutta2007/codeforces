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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n, m, q;
vector<int> g[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

map<pair<int, int>, long long> ans;
int c[maxn];
int depd[maxn];
int dep[maxn];
int diam[maxn];
int ts[maxn];
vector<int> vs[maxn];
vector<long long> ps[maxn];
vector<int> cnts[maxn];

void dfs0(int v, int p, int cc) {
  c[v] = cc;
  ts[cc]++;
  vs[cc].push_back(v);
  depd[v] = 0;
  int mx0 = 0, mx1 = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v, cc);
    depd[v] = max(depd[v], depd[u] + 1);
    if (depd[u] + 1 > mx0) {
      mx1 = mx0;
      mx0 = depd[u] + 1;
    } else if (depd[u] + 1 > mx1) {
      mx1 = depd[u] + 1;
    }
  }
  diam[cc] = max(diam[cc], mx0 + mx1);
}

void dfs1(int v, int p, int up) {
  dep[v] = max(depd[v], up);
  int mx0 = up, mx1 = up;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (depd[u] + 1 > mx0) {
      mx1 = mx0;
      mx0 = depd[u] + 1;
    } else if (depd[u] + 1 > mx1) {
      mx1 = depd[u] + 1;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    int nup;
    if (depd[u] + 1 == mx0) {
      nup = mx1;
    } else {
      nup = mx0;
    }
    nup++;
    dfs1(u, v, nup);
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    c[i] = -1;
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == -1) {
      ts[cc] = 0;
      vs[cc].clear();
      diam[cc] = 0;
      dfs0(i, -1, cc);
      dfs1(i, -1, 0);
      ps[cc].clear();
      cnts[cc].clear();
      for (int j = 0; j < sz(vs[cc]); j++) {
        int d = dep[vs[cc][j]];
        if (sz(ps[cc]) < d + 2) {
          ps[cc].resize(d + 2, 0);
          cnts[cc].resize(d + 2, 0);
        }
        ps[cc][d + 1] += d;
        cnts[cc][d + 1]++;
      }
      for (int j = 1; j < sz(ps[cc]); j++) {
        ps[cc][j] += ps[cc][j - 1];
        cnts[cc][j] += cnts[cc][j - 1];
      }
      /*eprintf("ts = %d\n", ts[cc]);
      for (int j = 0; j < sz(vs[cc]); j++) {
        eprintf("%d ", vs[cc][j]);
      }
      eprintf("\n");
      eprintf("diam = %d\n", diam[cc]);
      for (int j = 0; j < sz(ps[cc]); j++) {
        eprintf("%lld ", ps[cc][j]);
      }
      eprintf("\n");
      for (int j = 0; j < sz(ps[cc]); j++) {
        eprintf("%d ", cnts[cc][j]);
      }
      eprintf("\n");*/
      cc++;
    }
  }
  ans.clear();
  for (int qq = 0; qq < q; qq++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    v = c[v];
    u = c[u];
    if (v == u) {
      printf("-1\n");
      continue;
    }
    if (ts[v] > ts[u]) {
      swap(v, u);
    }
    if (!ans.count(make_pair(v, u))) {
      auto &cur = ans[make_pair(v, u)];
      cur = 0;
      int mx = max(diam[v], diam[u]);
      for (int i = 0; i < sz(vs[v]); i++) {
        int d = dep[vs[v][i]];
        int curmx = max(min(sz(ps[u]) - 1, mx - d - 1), 0);
        cur += (long long) (cnts[u].back() - cnts[u][curmx]) * (d + 1) + (ps[u].back() - ps[u][curmx]);
        cur += (long long) mx * cnts[u][curmx];
      }
    }
    long long todiv = (long long) ts[v] * ts[u];
    printf("%.12f\n", (double) ((ld) ans[make_pair(v, u)] / todiv));
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