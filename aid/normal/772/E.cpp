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

const int maxn = 2005;
int n;
vector<int> g[maxn];
int go[maxn][2];
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int ls[maxn][2];
int del[maxn];
int ts[maxn];

void dfs(int v, int pr) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (del[u] || u == pr) {
      continue;
    }
    dfs(u, v);
    ts[v] += ts[u];
  }
}

int getCentroid(int v) {
  dfs(v, -1);
  int pr = -1;
  int alls = ts[v];
  while (true) {
    int nv = -1;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (del[u] || u == pr) {
        continue;
      }
      if (ts[u] * 2 >= alls) {
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

char ask(int v, int leaf) {
  //eprintf("v = %d, leaf = %d\n", v, leaf);
  if (v < n) {
    return 'X';
  }
  printf("%d %d %d\n", ls[v][0] + 1, ls[v][1] + 1, leaf + 1);
  fflush(stdout);
  char tmp[10];
  scanf("%s", tmp);
  if (tmp[0] == '-') {
    exit(0);
  }
  return tmp[0];
}

void solve() {
  int freeid = n;
  for (int i = 0; i < 2 * n - 1; i++) {
    g[i].clear();
  }
  int root = freeid++;
  go[root][0] = 0;
  g[root].push_back(0);
  p[0] = root;
  g[0].push_back(root);
  ls[root][0] = 0;
  go[root][1] = 1;
  g[root].push_back(1);
  p[1] = root;
  g[1].push_back(root);
  ls[root][1] = 1;
  p[root] = -1;
  for (int i = 0; i < n; i++) {
    ls[i][0] = i;
    ls[i][1] = i;
  }
  for (int leaf = 2; leaf < n; leaf++) {
    /*for (int i = 0; i < 2 * n - 1; i++) {
      eprintf("%d: ", i);
      for (int j = 0; j < sz(g[i]); j++) {
        eprintf("%d ", g[i][j]);
      }
      eprintf("\n");
    }*/
    for (int i = 0; i < 2 * n - 1; i++) {
      del[i] = false;
    }
    int v = root;
    int pr = -1;
    while (v >= n && !del[v]) {
      v = getCentroid(v);
      del[v] = true;
      pr = v;
      char c = ask(v, leaf);
      if (c == 'X') {
        v = p[v];
      } else if (c == 'Y') {
        v = go[v][1];
      } else if (c == 'Z') {
        v = go[v][0];
      }
    }
    if (v == -1) {
      assert(pr == root);
      root = freeid++;
      go[root][0] = leaf;
      g[root].push_back(leaf);
      p[leaf] = root;
      g[leaf].push_back(root);
      ls[root][0] = leaf;
      go[root][1] = pr;
      g[root].push_back(pr);
      p[pr] = root;
      g[pr].push_back(root);
      ls[root][1] = ls[pr][1];
      p[root] = -1;
      continue;
    }
    int u = pr;
    assert(p[v] == u || p[u] == v);
    if (p[u] == v) {
      swap(v, u);
    }
    int w = freeid++;
    int side = (go[u][1] == v);
    assert(go[u][side] == v);
    go[u][side] = w;
    for (int i = 0; i < sz(g[u]); i++) {
      if (g[u][i] == v) {
        swap(g[u][i], g[u].back());
        g[u].pop_back();
        break;
      }
    }
    g[u].push_back(w);
    p[w] = u;
    g[w].push_back(u);
    p[v] = w;
    for (int i = 0; i < sz(g[v]); i++) {
      if (g[v][i] == u) {
        swap(g[v][i], g[v].back());
        g[v].pop_back();
        break;
      }
    }
    g[v].push_back(w);
    go[w][side] = v;
    g[w].push_back(v);
    go[w][side ^ 1] = leaf;
    g[w].push_back(leaf);
    p[leaf] = w;
    g[leaf].push_back(w);
    ls[w][side] = ls[v][side];
    ls[w][side ^ 1] = leaf;
  }
  assert(freeid == 2 * n - 1);
  printf("-1\n");
  for (int i = 0; i < 2 * n - 1; i++) {
    int pr = p[i];
    if (pr >= 0) {
      pr++;
    }
    printf("%d ", pr);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  precalc();
  assert(read());
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}