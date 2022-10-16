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

const int maxn = (int) 2e5 + 5;
int n, m, k;
int es[maxn][2];
vector<int> g[maxn];
vector<int> ids[maxn];
int deg[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    ids[i].clear();
    deg[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    es[i][0] = v;
    es[i][1] = u;
    g[v].push_back(u);
    ids[v].push_back(i);
    g[u].push_back(v);
    ids[u].push_back(i);
    deg[v]++;
    deg[u]++;
  }
  return true;
}

int del[maxn];
int ans[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  int cur = n;
  {
    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] < k) {
        del[i] = true;
        cur--;
        q.push_back(i);
      }
    }
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (del[u]) {
          continue;
        }
        deg[u]--;
        if (deg[u] < k) {
          del[u] = true;
          cur--;
          q.push_back(u);
        }
      }
    }
  }
  ans[m] = cur;
  for (int i = m - 1; i >= 0; i--) {
    int ev = es[i][0], eu = es[i][1];
    if (del[ev] || del[eu]) {
      ans[i] = cur;
      continue;
    }
    vector<int> q;
    for (int it = 0; it < 2; it++) {
      int v = (!it ? ev : eu);
      deg[v]--;
      if (deg[v] < k) {
        del[v] = true;
        cur--;
        q.push_back(v);
      }
    }
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int ii = 0; ii < sz(g[v]); ii++) {
        int u = g[v][ii];
        int id = ids[v][ii];
        if (del[u] || id >= i) {
          continue;
        }
        deg[u]--;
        if (deg[u] < k) {
          del[u] = true;
          cur--;
          q.push_back(u);
        }
      }
    }
    ans[i] = cur;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
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