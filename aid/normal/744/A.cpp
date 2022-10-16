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

const int maxn = 1005;
int n, m, k;
vector<int> g[maxn];
int c[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    c[i] = false;
    g[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    c[x] = true;
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

int used[maxn];

int dfs(int v) {
  used[v] = true;
  int res = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u]) {
      continue;
    }
    res += dfs(u);
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  int unused = n;
  int maxcnt = 0;
  long long res = -m;
  for (int i = 0; i < n; i++) {
    if (c[i]) {
      int cnt = dfs(i);
      unused -= cnt;
      maxcnt = max(maxcnt, cnt);
      res += (long long) cnt * (cnt - 1) / 2;
    }
  }
  res += (long long) unused * (unused - 1) / 2;
  res += (long long) unused * maxcnt;
  printf("%lld\n", res);
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