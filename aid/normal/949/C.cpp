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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n, m, h;
int x[maxn];
vector<int> g[maxn], gr[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &h) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    for (int it = 0; it < 2; it++) {
      if (x[u] == (x[v] + 1) % h) {
        g[v].push_back(u);
        gr[u].push_back(v);
      }
      swap(v, u);
    }
  }
  return true;
}

int used[maxn];
vector<int> p;

void dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (!used[u]) {
      dfs0(u);
    }
  }
  p.push_back(v);
}

int c[maxn];

void dfs1(int v, int col) {
  c[v] = col;
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (c[u] == -1) {
      dfs1(u, col);
    }
  }
}

int t[maxn];
vector<int> vs[maxn];

void solve() {
  p.clear();
  for (int i = 0; i < n; i++) {
    used[i] = false;
    c[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  reverse(p.begin(), p.end());
  int cs = 0;
  for (int i = 0; i < n; i++) {
    int v = p[i];
    if (c[v] == -1) {
      dfs1(v, cs++);
    }
  }
  for (int i = 0; i < cs; i++) {
    t[i] = true;
    vs[i].clear();
  }
  for (int v = 0; v < n; v++) {
    vs[c[v]].push_back(v);
    for (int i = 0; i < sz(g[v]) && t[c[v]]; i++) {
      int u = g[v][i];
      if (c[u] != c[v]) {
        t[c[v]] = false;
      }
    }
  }
  int res = inf;
  int id = -1;
  for (int i = 0; i < cs; i++) {
    if (t[i] && sz(vs[i]) < res) {
      res = sz(vs[i]);
      id = i;
    }
  }
  assert(id != -1);
  printf("%d\n", sz(vs[id]));
  for (int i = 0; i < sz(vs[id]); i++) {
    printf("%d ", vs[id][i] + 1);
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