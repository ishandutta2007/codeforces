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
int a[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < k; i++) {
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

int d[2][maxn];
vector<int> q;
pair<int, int> tosort[maxn];

void solve() {
  for (int t = 0; t < 2; t++) {
    int s = (!t ? 0 : n - 1);
    for (int i = 0; i < n; i++) {
      d[t][i] = inf;
    }
    q.clear();
    d[t][s] = 0;
    q.push_back(s);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (d[t][u] >= inf) {
          d[t][u] = d[t][v] + 1;
          q.push_back(u);
        }
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int v = a[i];
    tosort[i] = make_pair(d[0][v], v);
  }
  sort(tosort, tosort + k);
  int d0 = d[0][n - 1];
  int res = 0;
  for (int i = 1; i < k; i++) {
    int v = tosort[i].second;
    int cur = min(d0, tosort[i - 1].first + 1 + d[1][v]);
    res = max(res, cur);
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