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

const int maxn = (int) 2e5 + 5, logn = 20;
int n;
int a[maxn];
long long b[maxn];
int w[maxn];
int p[logn][maxn];
int res[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &p[0][i], &w[i]);
    p[0][i]--;
    g[p[0][i]].push_back(i);
  }
  return true;
}

void dfs(int v) {
  for (int i = 1; i < logn; i++) {
    p[i][v] = p[i - 1][p[i - 1][v]];
  }
  if (v) {
    int u = v;
    for (int i = logn - 1; i >= 0; i--) {
      if (b[p[i][u]] >= b[v] - a[v]) {
        u = p[i][u];
      }
    }
    res[p[0][v]]++;
    if (u) {
      res[p[0][u]]--;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    b[u] = b[v] + w[u];
    dfs(u);
  }
  if (v) {
    res[p[0][v]] += res[v];
  }
}

void solve() {
  p[0][0] = 0;
  b[0] = 0;
  for (int i = 0; i < n; i++) {
    res[i] = 0;
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}