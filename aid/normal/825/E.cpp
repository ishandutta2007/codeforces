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

const int maxn = (int) 1e5 + 5, logn = 20;
int n, m;
vector<int> g[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
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
  }
  return true;
}

int used[maxn];
int p[maxn][logn];
int dep[maxn];

bool cmp(int v, int u, int x) {
  if (dep[v] > dep[u]) {
    for (int it = logn - 1; it >= 0; it--) {
      if (dep[p[v][it]] > dep[u]) {
        v = p[v][it];
      }
    }
    int nxt = v;
    v = p[v][0];
    if (v == u) {
      return nxt < x;
    }
  } else if (dep[v] < dep[u]) {
    for (int it = logn - 1; it >= 0; it--) {
      if (dep[p[u][it]] > dep[v]) {
        u = p[u][it];
      }
    }
    int nxt = u;
    u = p[u][0];
    if (u == v) {
      return x < nxt;
    }
  } else {
    if (v == u) {
      return false;
    }
  }
  for (int it = logn - 1; it >= 0; it--) {
    if (p[v][it] != p[u][it]) {
      v = p[v][it];
      u = p[u][it];
    }
  }
  return v < u;
}

void dfs(int v) {
  used[v] = true;
  auto &curp = p[v][0];
  for (int i = 0; i < logn; i++) {
    p[v][i] = v;
  }
  auto &curdep = dep[v];
  curdep = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs(u);
    }
    int np = u;
    if (np > v) {
      for (int it = logn - 1; it >= 0; it--) {
        if (p[np][it] > v) {
          np = p[np][it];
        }
      }
      if (p[np][0] == np) {
        continue;
      }
      np = p[np][0];
    }
    if (cmp(np, curp, v)) {
      curp = np;
      for (int i = 1; i < logn; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
      }
      curdep = dep[np] + 1;
    }
  }
}

int ans[maxn];
vector<int> gt[maxn];
int t;

void getAns(int v) {
  sort(gt[v].begin(), gt[v].end());
  for (int i = 0; i < sz(gt[v]); i++) {
    getAns(gt[v][i]);
  }
  ans[v] = t++;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    gt[i].clear();
  }
  vector<int> roots;
  for (int i = 0; i < n; i++) {
    if (p[i][0] == i) {
      roots.push_back(i);
    } else {
      gt[p[i][0]].push_back(i);
    }
  }
  t = 0;
  sort(roots.begin(), roots.end());
  for (int i = 0; i < sz(roots); i++) {
    getAns(roots[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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