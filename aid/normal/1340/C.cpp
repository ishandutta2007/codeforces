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

const int maxl = (int) 1e6 + 5, maxn = (int) 1e4 + 5, maxg = 1005;
int l, n;
int a[maxn];
int g, r;

bool read() {
  if (scanf("%d%d", &l, &n) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d%d", &g, &r);
  return true;
}

int d[maxn][maxg];
vector<int> q0;
vector<int> vs[maxg];

void go() {
  for (int t = 0; t < g; t++) {
    for (int i = 0; i < sz(vs[t]); i++) {
      int v = vs[t][i];
      for (int it = 0; it < 2; it++) {
        int u = v + (!it ? -1 : 1);
        if (u < 0 || u >= n) {
          continue;
        }
        int w = abs(a[v] - a[u]);
        int ut = t + w;
        int dd = d[v][t] + w;
        if (ut <= g && dd < d[u][ut]) {
          d[u][ut] = dd;
          vs[ut].push_back(u);
        }
      }
    }
  }
  for (int i = 0; i < sz(vs[g]); i++) {
    int v = vs[g][i];
    int dd = d[v][g] + r;
    if (dd < d[v][0]) {
      d[v][0] = dd;
      q0.push_back(v);
    }
  }
}

void solve() {
  sort(a, a + n);
  for (int v = 0; v < n; v++) {
    for (int t = 0; t <= g; t++) {
      d[v][t] = inf;
    }
  }
  q0.clear();
  d[0][0] = 0;
  q0.push_back(0);
  for (int ql = 0; ql < sz(q0);) {
    for (int t = 0; t <= g; t++) {
      vs[t].clear();
    }
    int dd = d[q0[ql]][0];
    int qr = ql;
    while (qr < sz(q0) && d[q0[qr]][0] == dd) {
      vs[0].push_back(q0[qr]);
      qr++;
    }
    go();
    ql = qr;
  }
  int res = inf;
  for (int t = 0; t <= g; t++) {
    res = min(res, d[n - 1][t]);
  }
  if (res >= inf) {
    res = -1;
  }
  printf("%d\n", res);
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