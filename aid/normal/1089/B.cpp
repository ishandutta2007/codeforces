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

namespace Matching {
  const int maxn = 305;
  int n;
  vector<int> g[maxn];

  void addEdge(int v, int u) {
    g[v].push_back(u);
    g[u].push_back(v);
  }

  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  int match[maxn];
  int p[maxn];
  int t[maxn];
  int base[maxn];
  vector<int> q;

  int get(int v) {
    return (base[v] == v ? v : base[v] = get(base[v]));
  }

  int used[maxn];
  int curu;

  int getLca(int v, int u) {
    v = get(v);
    u = get(u);
    curu++;
    while (true) {
      if (v != -1) {
        if (used[v] == curu) {
          return v;
        }
        used[v] = curu;
        v = (match[v] == -1 ? -1 : get(p[match[v]]));
      }
      swap(v, u);
    }
  }

  void blossom(int v, int u, int b) {
    while (get(v) != b) {
      p[v] = u;
      u = match[v];
      if (t[u] == 1) {
        t[u] = 0;
        q.push_back(u);
      }
      base[v] = b;
      base[u] = b;
      v = p[u];
    }
  }

  void augment(int u, int v) {
    while (u != -1) {
      int nu = match[p[u]];
      match[u] = p[u];
      match[p[u]] = u;
      u = nu;
    }
  }

  bool bfs(int s) {
    for (int i = 0; i < n; i++) {
      p[i] = -1;
      t[i] = -1;
      base[i] = i;
    }
    q.clear();
    q.push_back(s);
    t[s] = 0;
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (t[u] == -1) {
          t[u] = 1;
          p[u] = v;
          if (match[u] == -1) {
            augment(u, v);
            return true;
          }
          int w = match[u];
          t[w] = 0;
          q.push_back(w);
        } else if (t[u] == 0 && get(v) != get(u)) {
          int b = getLca(v, u);
          blossom(v, u, b);
          blossom(u, v, b);
        }
      }
    }
    return false;
  }

  int solve() {
    for (int i = 0; i < n; i++) {
      match[i] = -1;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (match[i] == -1 && bfs(i)) {
        res++;
      }
    }
    return res;
  }
};

const int maxn = 155;
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

void solve() {
  Matching::init(2 * n + m);
  for (int i = 0; i < n; i++) {
    Matching::addEdge(2 * i, 2 * i + 1);
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '0') {
        continue;
      }
      Matching::addEdge(2 * i, 2 * n + j);
      Matching::addEdge(2 * i + 1, 2 * n + j);
    }
  }
  printf("%d\n", Matching::solve() - n);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}