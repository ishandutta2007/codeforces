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

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> g[maxn], gr[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
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
    g[v].push_back(u);
    gr[u].push_back(v);
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

int col[maxn];
vector<int> c[maxn];
int deg[maxn];
int pos[maxn];
int cs;

void dfs1(int v, int cc) {
  used[v] = true;
  col[v] = cc;
  c[cc].push_back(v);
  for (int i = 0; i < sz(gr[v]); i++) {
    int u = gr[v][i];
    if (!used[u]) {
      dfs1(u, cc);
    }
  }
}

int ask(int v, int u) {
  printf("? %d %d\n", v + 1, u + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

vector<int> q;

void del(int cc) {
  for (int i = 0; i < sz(c[cc]); i++) {
    int v = c[cc][i];
    for (int j = 0; j < sz(g[v]); j++) {
      int u = g[v][j];
      int cu = col[u];
      if (cu == cc) {
        continue;
      }
      deg[cu]--;
      if (!deg[cu]) {
        q.push_back(cu);
      }
    }
  }
}

int solveComps(int a, int b) {
  while (pos[a] < sz(c[a]) && pos[b] < sz(c[b])) {
    if (ask(c[a][pos[a]], c[b][pos[b]])) {
      pos[b]++;
    } else {
      pos[a]++;
    }
  }
  if (pos[a] >= sz(c[a])) {
    swap(a, b);
  }
  del(b);
  return a;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  p.clear();
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      dfs0(v);
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  cs = 0;
  for (int i = n - 1; i >= 0; i--) {
    int v = p[i];
    if (!used[v]) {
      c[cs].clear();
      deg[cs] = 0;
      pos[cs] = 0;
      dfs1(v, cs++);
    }
  }
  for (int v = 0; v < n; v++) {
    int cv = col[v];
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      int cu = col[u];
      if (cv == cu) {
        continue;
      }
      deg[cu]++;
    }
  }
  for (int i = 0; i < cs; i++) {
    if (!deg[i]) {
      q.push_back(i);
    }
  }
  assert(!q.empty());
  int curc = q[0];
  for (int l = 1; l < sz(q); l++) {
    int cc = q[l];
    curc = solveComps(curc, cc);
  }
  int res = c[curc][pos[curc]];
  printf("! %d\n", res + 1);
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}