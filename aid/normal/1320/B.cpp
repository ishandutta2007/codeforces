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
vector<int> g[maxn];
int p[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[u].push_back(v);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int d[maxn];
vector<int> q;
int cnt[maxn];

void solve() {
  q.clear();
  for (int i = 0; i < n; i++) {
    d[i] = inf;
  }
  d[p[k - 1]] = 0;
  q.push_back(p[k - 1]);
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (d[u] >= inf) {
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt[i] = 0;
  }
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (d[u] == d[v] + 1) {
        cnt[u]++;
      }
    }
  }
  int mn = 0, mx = 0;
  for (int i = 0; i + 1 < k; i++) {
    if (d[p[i]] != d[p[i + 1]] + 1) {
      mn++;
      mx++;
      continue;
    }
    if (cnt[p[i]] > 1) {
      mx++;
    }
  }
  printf("%d %d\n", mn, mx);
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