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

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxk = (int) 1e4 + 5;
int inv[maxk];

void precalc() {
  inv[1] = 1;
  for (int i = 2; i < maxk; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
}

long long n;
int k;

bool read() {
  if (scanf("%lld%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

vector<int> dp[maxk];

int get(long long p, int m) {
  {
    dp[0].resize(m + 1);
    long long x = 1;
    for (int i = 0; i <= m; i++) {
      dp[0][i] = x % mod;
      if (i + 1 <= m) {
        x *= p;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    dp[i].resize(m + 1);
    int sum = 0;
    for (int j = 0; j <= m; j++) {
      add(sum, dp[i - 1][j]);
      dp[i][j] = mul(sum, inv[j + 1]);
    }
  }
  return dp[k][m];
}

void solve() {
  int res = 1;
  for (long long d = 2; d * d <= n; d++) {
    if (!(n % d)) {
      int m = 0;
      while (!(n % d)) {
        n /= d;
        m++;
      }
      res = mul(res, get(d, m));
    }
  }
  if (n > 1) {
    res = mul(res, get(n, 1));
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