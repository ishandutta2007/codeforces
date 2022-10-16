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

const int maxn = (int) 2.5e5 + 5;
int n;
int es[2][maxn][2];
vector<int> g[2][maxn];
vector<int> ids[2][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      g[t][i].clear();
      ids[t][i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int v, u;
      scanf("%d%d", &v, &u);
      v--;
      u--;
      es[t][i][0] = v;
      es[t][i][1] = u;
      g[t][v].push_back(u);
      ids[t][v].push_back(i);
      g[t][u].push_back(v);
      ids[t][u].push_back(i);
    }
  }
  return true;
}

int p[maxn], pe[maxn];

void getP(int v, int pr, int pre) {
  p[v] = pr;
  pe[v] = pre;
  for (int i = 0; i < sz(g[0][v]); i++) {
    int u = g[0][v][i], id = ids[0][v][i];
    if (u == pr) {
      continue;
    }
    getP(u, v, id);
  }
}

int del[maxn];
int ans[maxn];

int ts[maxn];
vector<int> vs;

void dfs(int v, int p) {
  ts[v] = 1;
  vs.push_back(v);
  for (int i = 0; i < sz(g[1][v]); i++) {
    int u = g[1][v][i];
    if (u == p || del[u]) {
      continue;
    }
    dfs(u, v);
    ts[v] += ts[u];
  }
}

int getCentroid(int v) {
  vs.clear();
  dfs(v, -1);
  int k = ts[v];
  int pr = -1;
  while (true) {
    int nv = -1;
    for (int i = 0; i < sz(g[1][v]); i++) {
      int u = g[1][v][i];
      if (u == pr || del[u]) {
        continue;
      }
      if (2 * ts[u] > k) {
        nv = u;
        break;
      }
    }
    if (nv == -1) {
      break;
    }
    pr = v;
    v = nv;
  }
  return v;
}

int who[maxn];

void getWho(int v, int p, int w) {
  who[v] = w;
  for (int i = 0; i < sz(g[1][v]); i++) {
    int u = g[1][v][i];
    if (u == p || del[u]) {
      continue;
    }
    getWho(u, v, w);
  }
}

vector<int> gg[maxn];
int lst[maxn];

void recalc(int v) {
  int plst = -1;
  if (who[v] != -1) {
    p[v] = lst[who[v]];
    plst = lst[who[v]];
    lst[who[v]] = v;
  }
  for (int i = 0; i < sz(gg[v]); i++) {
    int u = gg[v][i];
    recalc(u);
  }
  if (who[v] != -1) {
    lst[who[v]] = plst;
  }
}

void buildCD(int v, int pr, int pre) {
  int root;
  if (pre != -1) {
    int u;
    for (u = v; p[u] != pr; u = p[u]) ;
    ans[pre] = pe[u];
    pe[u] = -1;
    root = u;
  } else {
    root = v;
  }
  v = getCentroid(v);
  for (int i = 0; i < sz(vs); i++) {
    int u = vs[i];
    if (p[u] == pr) {
      p[u] = root;
    }
  }
  /*eprintf("centroid = %d %d\n", v + 1, pr + 1);
  for (int i = 0; i < sz(vs); i++) {
    int v = vs[i];
    eprintf("%d: %d %d\n", v + 1, p[v] + 1, pe[v]);
  }*/
  vector<int> path, pes;
  for (int u = v;; u = p[u]) {
    path.push_back(u);
    pes.push_back(pe[u]);
    if (u == root) {
      break;
    }
  }
  rotate(pes.begin(), pes.end() - 1, pes.end());
  for (int i = 0; i < sz(path); i++) {
    int u = path[i];
    p[u] = (i ? path[i - 1] : pr);
    pe[u] = pes[i];
  }
  del[v] = true;
  who[v] = -1;
  for (int i = 0; i < sz(g[1][v]); i++) {
    int u = g[1][v][i];
    if (del[u]) {
      continue;
    }
    getWho(u, -1, u);
    lst[u] = v;
  }
  for (int i = 0; i < sz(vs); i++) {
    int u = vs[i];
    gg[u].clear();
  }
  for (int i = 0; i < sz(vs); i++) {
    int u = vs[i];
    gg[p[u]].push_back(u);
  }
  recalc(v);
  for (int i = 0; i < sz(g[1][v]); i++) {
    int u = g[1][v][i], id = ids[1][v][i];
    if (del[u]) {
      continue;
    }
    buildCD(u, v, id);
  }
}

void solve() {
  getP(0, -1, -1);
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  buildCD(0, -1, -1);
  printf("%d\n", n - 1);
  for (int i = 0; i < n - 1; i++) {
    printf("%d %d %d %d\n", es[0][ans[i]][0] + 1, es[0][ans[i]][1] + 1, es[1][i][0] + 1, es[1][i][1] + 1);
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