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

const int maxn = (int) 1e5 + 5, maxk = 105;
int n, m, k, s;
int a[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &m, &k, &s) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int ds[maxn][maxk];
int d[maxn];
vector<int> q;

void solve() {
  for (int t = 0; t < k; t++) {
    q.clear();
    for (int i = 0; i < n; i++) {
      d[i] = inf;
      if (a[i] == t) {
        d[i] = 0;
        q.push_back(i);
      }
    }
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (d[u] == inf) {
          d[u] = d[v] + 1;
          q.push_back(u);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      ds[i][t] = d[i];
    }
  }
  for (int v = 0; v < n; v++) {
    nth_element(ds[v], ds[v] + s - 1, ds[v] + k);
    int res = 0;
    for (int i = 0; i < s; i++) {
      res += ds[v][i];
    }
    printf("%d ", res);
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