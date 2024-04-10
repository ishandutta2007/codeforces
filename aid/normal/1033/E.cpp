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

const int maxn = 605;
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

vector<int> g[maxn];
int p[maxn], ts[maxn];
int col[maxn];
int es[maxn];
vector<int> vs[maxn];

int ask(const vector<int> &vs) {
  printf("? %d\n", sz(vs));
  for (int i = 0; i < sz(vs); i++) {
    printf("%d ", vs[i] + 1);
  }
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

int ask1(int v, const vector<int> &vs, int k) {
  assert(0 < k && k <= sz(vs));
  printf("? %d\n", k + 1);
  printf("%d ", v + 1);
  for (int i = 0; i < k; i++) {
    printf("%d ", vs[i] + 1);
  }
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1) {
    exit(0);
  }
  return res;
}

int getEdge(int v, const vector<int> &vs) {
  if (vs.empty() || !ask1(v, vs, sz(vs))) {
    return -1;
  }
  int l = 0, r = sz(vs);
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (!ask1(v, vs, m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return vs[r - 1];
}

bool getPath(int v, int to, int p, vector<int> &path) {
  path.push_back(v);
  if (v == to) {
    return true;
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    if (getPath(u, to, v, path)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

int get(int v) {
  return (p[v] == v ? v : p[v] = get(p[v]));
}

void unite(int v, int u, bool b) {
  v = get(v);
  u = get(u);
  if (ts[v] < ts[u]) {
    swap(v, u);
  }
  ts[v] += ts[u];
  p[u] = v;
  for (int i = 0; i < sz(vs[u]); i++) {
    vs[v].push_back(vs[u][i]);
    if (b) {
      col[vs[u][i]] ^= 1;
    }
  }
  vs[u].clear();
  es[v] = ask(vs[v]);
}

void add(int v, int root) {
  vector<int> a[2];
  for (int i = 0; i < sz(vs[root]); i++) {
    int u = vs[root][i];
    a[col[u]].push_back(u);
  }
  int e0 = getEdge(v, a[0]), e1 = getEdge(v, a[1]);
  assert(e0 != -1 || e1 != -1);
  if (e0 != -1 && e1 != -1) {
    vector<int> path;
    getPath(e0, e1, -1, path);
    path.push_back(v);
    printf("N %d\n", sz(path));
    for (int i = 0; i < sz(path); i++) {
      printf("%d ", path[i] + 1);
    }
    printf("\n");
    fflush(stdout);
    exit(0);
  }
  int u = (e0 == -1 ? e1 : e0);
  g[v].push_back(u);
  g[u].push_back(v);
  unite(v, u, col[v] == col[u]);
}

int askRoots(const vector<int> &roots, int k) {
  vector<int> all;
  int res = 0;
  for (int i = 0; i < k; i++) {
    int v = roots[i];
    if (p[v] != v) {
      continue;
    }
    res -= es[v];
    for (int j = 0; j < sz(vs[v]); j++) {
      all.push_back(vs[v][j]);
    }
  }
  res += ask(all);
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    g[i].clear();
    p[i] = i;
    ts[i] = 1;
    col[i] = 0;
    es[i] = 0;
    vs[i] = {i};
  }
  for (int v = 1; v < n; v++) {
    vector<int> roots;
    roots.push_back(v);
    for (int i = 0; i < v; i++) {
      if (p[i] == i) {
        roots.push_back(i);
      }
    }
    int all = askRoots(roots, sz(roots));
    int pos = 1;
    while (all) {
      int l = pos, r = sz(roots);
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (askRoots(roots, m)) {
          r = m;
        } else {
          l = m;
        }
      }
      add(v, roots[r - 1]);
      pos = r;
      all = askRoots(roots, sz(roots));
    }
  }
  vector<int> a;
  for (int i = 0; i < n; i++) {
    if (!col[i]) {
      a.push_back(i);
    }
  }
  printf("Y %d\n", sz(a));
  for (int i = 0; i < sz(a); i++) {
    printf("%d ", a[i] + 1);
  }
  printf("\n");
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