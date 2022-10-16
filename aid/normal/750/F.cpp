#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = 205;
int h;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &h) < 1) {
    return false;
  }
  for (int i = 0; i < (1 << h) - 1; i++) {
    g[i].clear();
  }
  if (!h) {
    exit(0);
  }
  return true;
}

void get(int v) {
  if (!g[v].empty()) {
    return;
  }
  printf("? %d\n", v + 1);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  if (!k) {
    exit(0);
  }
  g[v].resize(k);
  for (int i = 0; i < k; i++) {
    int u;
    scanf("%d", &u);
    u--;
    g[v][i] = u;
  }
}

void printAns(int v) {
  printf("! %d\n", v + 1);
  fflush(stdout);
}

void solve() {
  int v = 0;
  get(v);
  int vh;
  int pv;
  if (sz(g[v]) > 1) {
    vector<int> path;
    path.push_back(v);
    for (int i = 0; i < 2; i++) {
      int u = g[v][i];
      int pu = v;
      while (true) {
        if (i) {
          path.insert(path.begin(), u);
        } else {
          path.push_back(u);
        }
        get(u);
        if (sz(g[u]) == 1) {
          break;
        }
        int nu = (g[u][0] == pu ? g[u][1] : g[u][0]);
        pu = u;
        u = nu;
      }
    }
    assert(sz(path) & 1);
    v = path[sz(path) / 2];
    if (sz(g[v]) == 2) {
      printAns(v);
      return;
    }
    int u = -1;
    for (int i = 0; i < sz(g[v]); i++) {
      int w = g[v][i];
      bool ok = true;
      for (int j = 0; j < sz(path); j++) {
        if (w == path[j]) {
          ok = false;
        }
      }
      if (ok) {
        u = w;
      }
    }
    assert(u != -1);
    pv = v;
    v = u;
    vh = sz(path) / 2 + 2;
  } else {
    pv = v;
    v = g[v][0];
    vh = 2;
  }
  while (vh < h - 2) {
    get(v);
    int nv = (g[v][0] == pv ? g[v][1] : g[v][0]);
    int u = nv;
    int pu = v;
    for (int i = 0; i < vh - 2; i++) {
      get(u);
      assert(sz(g[u]) > 1);
      int nu = (g[u][0] == pu ? g[u][1] : g[u][0]);
      pu = u;
      u = nu;
    }
    get(u);
    if (sz(g[u]) == 1) {
      int nnv = -1;
      for (int i = 0; i < sz(g[v]); i++) {
        if (g[v][i] != pv && g[v][i] != nv) {
          nnv = g[v][i];
        }
      }
      assert(nnv != -1);
      nv = nnv;
    }
    pv = v;
    v = nv;
    vh++;
  }
  if (vh == h) {
    printAns(v);
    return;
  }
  if (vh == h - 1) {
    get(v);
    int u = (g[v][0] == pv ? g[v][1] : g[v][0]);
    get(u);
    if (sz(g[u]) != 2) {
      int nu = -1;
      for (int i = 0; i < sz(g[v]); i++) {
        if (g[v][i] != pv && g[v][i] != u) {
          nu = g[v][i];
        }
      }
      assert(nu != -1);
      u = nu;
    }
    printAns(u);
    return;
  }
  get(v);
  vector<int> vec;
  for (int i = 0; i < sz(g[v]); i++) {
    if (g[v][i] == pv) {
      continue;
    }
    int u = g[v][i];
    get(u);
    for (int j = 0; j < sz(g[u]); j++) {
      int w = g[u][j];
      if (w != v) {
        vec.push_back(w);
      }
    }
  }
  assert(sz(vec) <= 4);
  for (int i = 0; i < sz(vec) - 1; i++) {
    int u = vec[i];
    get(u);
    if (sz(g[u]) == 2) {
      printAns(u);
      return;
    }
  }
  printAns(vec.back());
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    assert(read());
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}