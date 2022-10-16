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

const int maxn = (int) 1e6 + 5;
int n;
int op[maxn];
int p[maxn];
vector<int> g[maxn];
char tmp[100];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    p[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    if (tmp[0] == 'I') {
      scanf("%d", &op[i]);
    } else if (tmp[0] == 'N') {
      op[i] = 2;
      int v;
      scanf("%d", &v);
      v--;
      g[i].push_back(v);
      p[v] = i;
    } else {
      op[i] = (tmp[0] == 'A' ? 3 : (tmp[0] == 'O' ? 4 : 5));
      for (int it = 0; it < 2; it++) {
        int v;
        scanf("%d", &v);
        v--;
        g[i].push_back(v);
        p[v] = i;
      }
    }
  }
  return true;
}

int val[maxn];
int dp[maxn];

int getOp(int op, int a, int b) {
  if (op < 2) {
    return op;
  }
  if (op == 2) {
    return !a;
  }
  if (op == 3) {
    return (a && b);
  }
  if (op == 4) {
    return (a || b);
  }
  if (op == 5) {
    return (a ^ b);
  }
  assert(false);
}

void dfs0(int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs0(u);
  }
  val[v] = getOp(op[v], (g[v].empty() ? -1 : val[g[v][0]]), (sz(g[v]) < 2 ? -1 : val[g[v][1]]));
}

void dfs(int v) {
  if (p[v] == -1) {
    dp[v] = !val[v];
  } else {
    int u = p[v];
    int a = (g[u].empty() ? -1 : g[u][0]), b = (sz(g[u]) < 2 ? -1 : g[u][1]);
    for (int it = 0; it < 2; it++) {
      auto &cur = (!it ? a : b);
      if (cur == -1) {
        continue;
      }
      cur = (cur == v ? !val[cur] : val[cur]);
    }
    int x = getOp(op[u], a, b);
    dp[v] = (x == val[u] ? val[0] : dp[u]);
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
  }
}

void solve() {
  dfs0(0);
  dfs(0);
  string ans;
  for (int i = 0; i < n; i++) {
    if (op[i] < 2) {
      ans += (char) ('0' + dp[i]);
    }
  }
  printf("%s\n", ans.c_str());
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