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
int n, m;
vector<int> g[2][maxn];
int used[2][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      g[t][i].clear();
      used[t][i] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[0][v].push_back(u);
    g[1][u].push_back(v);
  }
  return true;
}

bool dfs(int t, int v) {
  used[t][v] = 1;
  for (int i = 0; i < sz(g[t][v]); i++) {
    int u = g[t][v][i];
    if (used[t][u] == 1) {
      return false;
    }
    if (used[t][u] == 2) {
      continue;
    }
    if (!dfs(t, u)) {
      return false;
    }
  }
  used[t][v] = 2;
  return true;
}

string ans;

void solve() {
  ans = "";
  int res = 0;
  for (int v = 0; v < n; v++) {
    if (used[0][v] || used[1][v]) {
      ans += 'E';
    } else {
      ans += 'A';
      res++;
    }
    if (!used[0][v]) {
      if (!dfs(0, v)) {
        printf("-1\n");
        return;
      }
    }
    if (!used[1][v]) {
      if (!dfs(1, v)) {
        printf("-1\n");
        return;
      }
    }
  }
  printf("%d\n%s\n", res, ans.c_str());
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