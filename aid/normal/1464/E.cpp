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

const int mod = 998244353;

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

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
  }
  return true;
}

int used[maxn];
int gr[maxn];
const int maxx = 1025;
int p[maxx];

vector<int> mex;

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (!used[u]) {
      dfs(u);
    }
  }
  mex.clear();
  mex.resize(sz(g[v]) + 1);
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (gr[u] < sz(mex)) {
      mex[gr[u]] = true;
    }
  }
  gr[v] = 0;
  while (mex[gr[v]]) {
    ++gr[v];
  }
}

int a[maxx][maxx];

void solveEq(int n) {
  for (int i = 0; i < n; ++i) {
    {
      int row = -1;
      for (int j = i; j < n; ++j) {
        if (a[j][i]) {
          row = j;
          break;
        }
      }
      for (int k = i; k <= n; ++k) {
        swap(a[i][k], a[row][k]);
      }
    }
    {
      int tomul = inv(a[i][i]);
      for (int j = i; j <= n; ++j) {
        a[i][j] = mul(a[i][j], tomul);
      }
    }
    for (int j = 0; j < n; ++j) {
      if (j == i) {
        continue;
      }
      int tomul = a[j][i];
      for (int k = i; k <= n; ++k) {
        add(a[j][k], mod - mul(tomul, a[i][k]));
      }
    }
  }
}

void solve() {
  for (int i = 0; i < maxx; ++i) {
    p[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    used[i] = false;
  }
  int k = 0;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
    ++p[gr[i]];
    while ((1 << k) <= gr[i]) {
      ++k;
    }
  }
  int q = inv(n + 1);
  for (int i = 0; i < (1 << k); ++i) {
    p[i] = mul(p[i], q);
  }
  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j <= (1 << k); ++j) {
      a[i][j] = 0;
    }
    add(a[i][i], 1);
    for (int j = 0; j < (1 << k); ++j) {
      add(a[i][j], mod - p[j ^ i]);
    }
    if (!i) {
      add(a[i][1 << k], q);
    }
  }
  solveEq(1 << k);
  int res = 1;
  add(res, mod - a[0][1 << k]);
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