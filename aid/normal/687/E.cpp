#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 5005;
int n, m;
int used[maxn], col[maxn], leaf[maxn], minc[maxn];
vector<int> g[maxn], gr[maxn], gc[maxn], p;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
    gc[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    gr[u].push_back(v);
  }
  return true;
}

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

void dfs1(int v, int c) {
  used[v] = true;
  col[v] = c;
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (!used[u]) {
      dfs1(u, c);
    }
  }
}

int q[maxn], d[maxn];

int getCycle(int s) {
  for (int i = 0; i < n; i++) {
    used[i] = false;
    d[i] = inf;
  }
  int r = 0;
  for (int i = 0; i < sz(g[s]); i++) {
    int u = g[s][i];
    d[u] = 1;
    q[r++] = u;
  }
  if (!r) {
    return 0;
  }
  for (int l = 0; l < r && d[s] == inf; l++) {
    int v = q[l];
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q[r++] = u;
      }
    }
  }
  return d[s];
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  p.clear();
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  int cs = 0;
  for (int i = n - 1; i >= 0; i--) {
    int v = p[i];
    if (!used[v]) {
      dfs1(v, cs++);
    }
  }
  for (int i = 0; i < cs; i++) {
    leaf[i] = true;
    minc[i] = inf;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(g[i]); j++) {
      int u = g[i][j];
      if (col[u] != col[i]) {
        leaf[col[i]] = false;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (leaf[col[i]]) {
      minc[col[i]] = min(minc[col[i]], getCycle(i));
    }
  }
  int ans = n;
  for (int i = 0; i < cs; i++) {
    if (leaf[i] && minc[i]) {
      ans += 998 * minc[i] + 1;
    }
  }
  printf("%d\n", ans);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}