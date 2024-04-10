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

const int maxn = (int) 1e3 + 5;
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

const int maxx = (int) 1e5 + 5;
int cnt[maxx];
int dp[maxn], ndp[maxn];

void solve() {
  sort(a, a + n);
  int y = a[n - 1] - a[0];
  memset(cnt, 0, sizeof(cnt));
  for (int x = 0; x * (k - 1) <= y; x++) {
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
    }
    for (int kk = 1; kk < k; kk++) {
      for (int i = 0; i < n; i++) {
        ndp[i] = 0;
      }
      for (int i = 0, j = 0; i < n; i++) {
        auto cur = dp[i];
        if (!cur) {
          continue;
        }
        j = max(j, i + 1);
        while (j < n && a[j] - a[i] < x) {
          j++;
        }
        if (j < n) {
          add(ndp[j], cur);
        }
      }
      for (int i = 0; i + 1 < n; i++) {
        add(ndp[i + 1], ndp[i]);
      }
      swap(dp, ndp);
    }
    for (int i = 0; i < n; i++) {
      add(cnt[x], dp[i]);
    }
  }
  int res = 0;
  for (int x = 0; x + 1 < maxx; x++) {
    int cur = cnt[x];
    add(cur, mod - cnt[x + 1]);
    add(res, mul(x, cur));
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