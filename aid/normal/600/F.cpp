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

const int maxn = 1005, maxm = (int) 1e5 + 5;
int n[2], m;
vector<int> g[2][maxn], ids[2][maxn];

bool read() {
  if (scanf("%d%d%d", &n[0], &n[1], &m) < 3) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int v = 0; v < n[t]; v++) {
      g[t][v].clear();
      ids[t][v].clear();
    }
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[0][v].push_back(u);
    ids[0][v].push_back(i);
    g[1][u].push_back(v);
    ids[1][u].push_back(i);
  }
  return true;
}

int c[maxm];
int p[2][maxn], pe[2][maxn];
int used[2][maxn];
int curu;

bool dfs(int t, int v, int d) {
  used[t][v] = curu;
  for (int i = 0; i < sz(g[t][v]); i++) {
    int u = g[t][v][i], e = ids[t][v][i];
    int w = p[!t][u], ee = pe[!t][u];
    if (w == -1) {
      p[!t][u] = v;
      pe[!t][u] = e;
      p[t][v] = u;
      pe[t][v] = e;
      c[e] = d;
      return true;
    }
    if (sz(g[t][w]) < d) {
      p[t][w] = -1;
      pe[t][w] = -1;
      c[ee] = -1;
      p[!t][u] = v;
      pe[!t][u] = e;
      p[t][v] = u;
      pe[t][v] = e;
      c[e] = d;
      return true;
    }
  }
  for (int i = 0; i < sz(g[t][v]); i++) {
    int u = g[t][v][i], e = ids[t][v][i];
    int w = p[!t][u], ee = pe[!t][u];
    if (used[t][w] != curu && dfs(t, w, d)) {
      c[ee] = -1;
      p[!t][u] = v;
      pe[!t][u] = e;
      p[t][v] = u;
      pe[t][v] = e;
      c[e] = d;
      return true;
    }
  }
  return false;
}

int perm[maxn];

void solve() {
  for (int i = 0; i < m; i++) {
    c[i] = -1;
  }
  int d = 0;
  for (int t = 0; t < 2; t++) {
    for (int v = 0; v < n[t]; v++) {
      d = max(d, sz(g[t][v]));
      vector<pair<int, int>> es;
      for (int i = 0; i < sz(g[t][v]); i++) {
        es.push_back(make_pair(g[t][v][i], ids[t][v][i]));
      }
      shuffle(es.begin(), es.end(), mrand);
      for (int i = 0; i < sz(g[t][v]); i++) {
        g[t][v][i] = es[i].first;
        ids[t][v][i] = es[i].second;
      }
    }
  }
  for (int dd = d; dd > 0; dd--) {
    for (int t = 0; t < 2; t++) {
      for (int v = 0; v < n[t]; v++) {
        p[t][v] = -1;
        pe[t][v] = -1;
        int k = 0;
        for (int i = 0; i < sz(g[t][v]); i++) {
          int u = g[t][v][i], e = ids[t][v][i];
          if (c[e] == -1) {
            g[t][v][k] = u;
            ids[t][v][k] = e;
            k++;
          }
        }
        g[t][v].resize(k);
        ids[t][v].resize(k);
      }
    }
    for (int t = 0; t < 2; t++) {
      for (int v = 0; v < n[t]; v++) {
        perm[v] = v;
      }
      shuffle(perm, perm + n[t], mrand);
      for (int i = 0; i < n[t]; i++) {
        int v = perm[i];
        if (p[t][v] == -1 && sz(g[t][v]) == dd) {
          curu++;
          assert(dfs(t, v, dd));
        }
      }
    }
  }
  printf("%d\n", d);
  for (int i = 0; i < m; i++) {
    printf("%d ", c[i]);
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