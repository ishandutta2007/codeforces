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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

const int maxn = (int) 2e5 + 5;
int n;
vector<int> g[maxn];
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2 * n; i++) {
    g[i].clear();
    p[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[u].push_back(v);
    p[v] = u;
  }
  return true;
}

int used[maxn];

int dfs(int v) {
  used[v] = 2;
  int res = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    res += dfs(g[v][i]);
  }
  return res;
}

bool getCycle(int v, vector<int> &c) {
  used[v] = 1;
  c.push_back(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u] == 2) {
      continue;
    }
    if (used[u] == 1) {
      used[v] = 2;
      return true;
    }
    if (getCycle(u, c)) {
      used[v] = 2;
      return true;
    }
  }
  used[v] = 2;
  c.pop_back();
  return false;
}

void solve() {
  n *= 2;
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (p[i] == -1) {
      res = mul(res, dfs(i));
    }
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    vector<int> c;
    if (!getCycle(i, c)) {
      continue;
    }
    if (sz(c) > 1) {
      res = mul(res, 2);
    }
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