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

const int maxn = (int) 5e5 + 5;
int n, m;
vector<int> g[maxn];
int c[maxn];

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
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
  }
  return true;
}

vector<int> vs[maxn];
int a[maxn];
int curu;
int used[maxn];
vector<int> ans;

void solve() {
  for (int i = 0; i < n; i++) {
    vs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    vs[c[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    a[i] = -1;
  }
  ans.clear();
  for (int col = 0; col < n; col++) {
    for (int i = 0; i < sz(vs[col]); i++) {
      int v = vs[col][i];
      curu++;
      for (int j = 0; j < sz(g[v]); j++) {
        int u = g[v][j];
        if (a[u] != -1) {
          used[a[u]] = curu;
        }
      }
      auto &cur = a[v];
      cur = 0;
      while (used[cur] == curu) {
        cur++;
      }
      if (cur != c[v]) {
        printf("-1\n");
        return;
      }
      ans.push_back(v);
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
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