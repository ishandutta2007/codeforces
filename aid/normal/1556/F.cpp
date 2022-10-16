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

const int mod = (int) 1e9 + 7;

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

const int maxn = 15, pown = (1 << maxn);
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

int g[maxn][maxn];
int mem[maxn][pown];
int dp[pown];

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int q = inv(a[i] + a[j]);
      g[i][j] = mul(a[i], q);
      g[j][i] = mul(a[j], q);
    }
  }
  for (int v = 0; v < n; ++v) {
    for (int msk = 0; msk < (1 << n); ++msk) {
      auto &cur = mem[v][msk];
      cur = 1;
      for (int u = 0; u < n; ++u) {
        if (!(msk & (1 << u))) {
          continue;
        }
        cur = mul(cur, g[v][u]);
      }
    }
  }
  for (int msk = 1; msk < (1 << n); ++msk) {
    auto &cur = dp[msk];
    cur = 1;
    for (int sub = ((msk - 1) & msk); sub > 0; sub = ((sub - 1) & msk)) {
      int pr = dp[sub];
      for (int v = 0; v < n; ++v) {
        if (!(sub & (1 << v))) {
          continue;
        }
        pr = mul(pr, mem[v][msk ^ sub]);
      }
      add(cur, mod - pr);
    }
  }
  int res = 0;
  for (int msk = 1; msk < (1 << n); ++msk) {
    auto cur = dp[msk];
    for (int v = 0; v < n; ++v) {
      if (!(msk & (1 << v))) {
        continue;
      }
      cur = mul(cur, mem[v][((1 << n) - 1) ^ msk]);
    }
    add(res, mul(__builtin_popcount(msk), cur));
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