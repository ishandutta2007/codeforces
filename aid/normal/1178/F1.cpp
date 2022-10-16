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

const int maxn = 505;
int n, m;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int dp[maxn][maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      int id = n;
      int pos = -1;
      for (int k = i; k < j; k++) {
        if (a[k] < id) {
          id = a[k];
          pos = k;
        }
      }
      int l = 0;
      for (int k = i; k <= pos; k++) {
        add(l, mul(dp[i][k], dp[k][pos]));
      }
      int r = 0;
      for (int k = pos + 1; k <= j; k++) {
        add(r, mul(dp[pos + 1][k], dp[k][j]));
      }
      dp[i][j] = mul(l, r);
    }
  }
  printf("%d\n", dp[0][n]);
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