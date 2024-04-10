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

const int maxn = 105;
int n;
int c[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    scanf("%d", &b[i]);
  }
  return true;
}

const int maxx = maxn * maxn;
int dp[maxx], ndp[maxx];

void solve() {
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; ++qq) {
    int x;
    scanf("%d", &x);
    for (int i = 0; i < maxx; ++i) {
      dp[i] = 0;
    }
    dp[0] = 1;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += x;
      int sum = 0;
      for (int j = 0, k = 0; j < maxx; ++j) {
        add(sum, dp[j]);
        while (j - k > c[i]) {
          add(sum, mod - dp[k]);
          ++k;
        }
        ndp[j] = (j < s ? 0 : sum);
      }
      swap(dp, ndp);
      if (i + 1 < n) {
        x += b[i];
      }
    }
    int res = 0;
    for (int i = 0; i < maxx; ++i) {
      add(res, dp[i]);
    }
    printf("%d\n", res);
  }
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