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

const int mod = (int) 1e9 + 7;
const int inv2 = (mod + 1) / 2;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  auto p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = 205;
int dp[maxn][maxn];

void precalc() {
  for (int j = 1; j < maxn; ++j) {
    dp[0][j] = 0;
  }
  for (int i = 1; i < maxn; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j < maxn; ++j) {
      auto &cur = dp[i][j];
      cur = dp[i - 1][j];
      add(cur, dp[i][j - 1]);
      cur = mul(cur, inv2);
    }
  }
}

int n;
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int ts[maxn];

void dfs0(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs0(u, v);
    ts[v] += ts[u];
  }
}

int invn;
vector<int> path;
int res;

void dfs(int v, int p) {
  path.push_back(v);
  if (v > path[0]) {
    for (int i = 0; i < sz(path); ++i) {
      int cnt = ts[path[i]] - (i + 1 < sz(path) ? ts[path[i + 1]] : 0);
      add(res, mul(mul(cnt, invn), dp[i][sz(path) - i - 1]));
    }
  }
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  path.pop_back();
}

void solve() {
  path.clear();
  res = 0;
  invn = inv(n);
  for (int s = 0; s < n; ++s) {
    dfs0(s, -1);
    dfs(s, -1);
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