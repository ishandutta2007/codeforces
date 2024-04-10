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

const int maxn = 2005;
char tmp[maxn];
int n;
bitset<maxn> g[maxn], gr[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].reset();
    gr[i].reset();
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < n; j++) {
      g[i][j] = (tmp[j] - '0');
      gr[j][i] = (tmp[j] - '0');
    }
  }
  return true;
}

bitset<maxn> used;
vector<int> p;

void dfs0(int v) {
  used[v] = true;
  for (int u = (g[v] & ~used)._Find_first(); u < n; u = (g[v] & ~used)._Find_next(u)) {
    dfs0(u);
  }
  p.push_back(v);
}

int c[maxn];

void dfs1(int v, int cid) {
  used[v] = true;
  c[v] = cid;
  for (int u = (gr[v] & ~used)._Find_first(); u < n; u = (gr[v] & ~used)._Find_next(u)) {
    dfs1(u, cid);
  }
}

int cc[maxn];

void solve() {
  used.reset();
  p.clear();
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs0(i);
    }
  }
  for (int i = 0; i < n; i++) {
    c[i] = -1;
  }
  used.reset();
  int cs = 0;
  for (int i = n - 1; i >= 0; i--) {
    int v = p[i];
    if (!used[v]) {
      dfs1(v, cs++);
    }
  }
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] == 0) {
      c0++;
    }
    if (c[i] == cs - 1) {
      c1++;
    }
  }
  if (cs == 1) {
    printf("0 1\n");
    return;
  }
  if (cs >= 3 || c0 >= 4 || c1 >= 4) {
    for (int i = 0; i < n; i++) {
      cc[i] = c[i];
    }
    int k = 0;
    for (int v = 0; v < n; v++) {
      if (cc[v] != 0 && cc[v] != cs - 1) {
        k++;
        continue;
      }
      for (int u = 0; u < n; u++) {
        if (u == v) {
          continue;
        }
        g[v][u] = !g[v][u];
        g[u][v] = !g[u][v];
        gr[v][u] = !gr[v][u];
        gr[u][v] = !gr[u][v];
      }
      used.reset();
      p.clear();
      for (int i = 0; i < n; i++) {
        if (!used[i]) {
          dfs0(i);
        }
      }
      for (int i = 0; i < n; i++) {
        c[i] = -1;
      }
      used.reset();
      int cs = 0;
      for (int i = n - 1; i >= 0; i--) {
        int v = p[i];
        if (!used[v]) {
          dfs1(v, cs++);
          break;
        }
      }
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (!used[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        k++;
      }
      for (int u = 0; u < n; u++) {
        if (u == v) {
          continue;
        }
        g[v][u] = !g[v][u];
        g[u][v] = !g[u][v];
        gr[v][u] = !gr[v][u];
        gr[u][v] = !gr[u][v];
      }
    }
    printf("1 %d\n", k);
    return;
  }
  if (c0 == 3 && c1 == 3) {
    printf("2 18\n");
    return;
  }
  printf("-1\n");
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