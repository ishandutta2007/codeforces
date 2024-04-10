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

struct Edge {
  int to, c, f;

  Edge(int _to, int _c): to(_to), c(_c), f(0) {}
};

const int maxn = (int)1e4 + 5;
int n, m;
int used[maxn], cut[maxn], tin[maxn], f[maxn], tt;
vector<int> colcnt;
vector< pair<int, int> > cac[maxn];
vector<int> ecac, eused;
vector< vector<int> > c;
vector<Edge> e;
vector< vector<int> > g;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    cac[i].clear();
  }
  ecac.clear();
  colcnt.resize(m);
  for (int i = 0; i < m; i++) {
    colcnt[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int v, u, col;
    scanf("%d%d%d", &v, &u, &col);
    v--;
    u--;
    col--;
    cac[v].push_back(make_pair(u, sz(ecac)));
    cac[u].push_back(make_pair(v, sz(ecac)));
    ecac.push_back(col);
    colcnt[col]++;
  }
  return true;
}

void getCuts(int v, int p) {
  used[v] = true;
  tin[v] = tt++;
  f[v] = tin[v];
  cut[v] = false;
  int cnt = 0;
  for (int i = 0; i < sz(cac[v]); i++) {
    int u = cac[v][i].first;
    if (used[u]) {
      f[v] = min(f[v], tin[u]);
    }
    else {
      getCuts(u, v);
      f[v] = min(f[v], f[u]);
      if (f[u] >= tin[v] && p != -1) {
        cut[v] = true;
      }
      cnt++;
    }
  }
  if (p == -1 && cnt > 1) {
    cut[v] = true;
  }
}

void addEcac(int eid, int cid) {
  if (eused[eid]) {
    return;
  }
  eused[eid] = true;
  c[cid].push_back(ecac[eid]);
}

void getC(int v, int p, int cid) {
  used[v] = true;
  bool bb = false;
  for (int i = 0; i < sz(cac[v]); i++) {
    int u = cac[v][i].first, eid = cac[v][i].second;
    if (used[u]) {
      addEcac(eid, cid);
    }
    else {
      if ((f[u] >= tin[v] && p != -1) || (p == -1 && cut[v] && bb)) {
        int nid = sz(c);
        c.push_back(vector<int>());
        addEcac(eid, nid);
        getC(u, v, nid);
      }
      else {
        addEcac(eid, cid);
        getC(u, v, cid);
      }
      bb = true;
    }
  }
}

void addEdge(int v, int u, int  cap) {
  g[v].push_back(sz(e));
  e.push_back(Edge(u, cap));
  g[u].push_back(sz(e));
  e.push_back(Edge(v, 0));
}

vector<int> pos, d;

bool bfs(int s, int t, int n) {
  for (int i = 0; i < n; i++) {
    d[i] = inf;
  }
  d[s] = 0;
  vector<int> q;
  q.push_back(s);
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i], u = e[id].to, cf = e[id].c - e[id].f;
      if (cf && d[u] >= inf) {
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
  }
  return d[t] < inf;
}

int dfs(int v, int t, int mincf) {
  if (v == t) {
    return mincf;
  }
  for (; pos[v] < sz(g[v]); pos[v]++) {
    int id = g[v][pos[v]], u = e[id].to, cf = e[id].c - e[id].f;
    if (d[u] == d[v] + 1 && cf) {
      int f = dfs(u, t, min(mincf, cf));
      if (f) {
        e[id].f += f;
        e[id ^ 1].f -= f;
        return f;
      }
    }
  }
  return 0;
}

int maxFlow(int s, int t, int n) {
  int flow = 0;
  pos.resize(n);
  d.resize(n);
  while (bfs(s, t, n)) {
    for (int i = 0; i < n; i++) {
      pos[i] = 0;
    }
    while (int f = dfs(s, t, inf)) {
      flow += f;
    }
  }
  return flow;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  tt = 0;
  getCuts(0, -1);
  c.clear();
  c.push_back(vector<int>());
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  eused.resize(sz(ecac));
  for (int i = 0; i < sz(eused); i++) {
    eused[i] = false;
  }
  getC(0, -1, 0);
  e.clear();
  g.clear();
  int cs = sz(c), s = cs + m, t = s + 1;
  g.resize(cs + m + 2);
  int needflow = 0;
  for (int i = 0; i < cs; i++) {
    if (sz(c[i]) <= 1) {
      continue;
    }
    needflow++;
    addEdge(s, i, 1);
    for (int j = 0; j < sz(c[i]); j++) {
      addEdge(i, cs + c[i][j], 1);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (colcnt[i]) {
      ans++;
    }
    if (colcnt[i] > 1) {
      addEdge(cs + i, t, colcnt[i] - 1);
    }
  }
  printf("%d\n", ans - (needflow - maxFlow(s, t, cs + m + 2)));
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