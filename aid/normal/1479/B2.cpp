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

const int maxn = (int) 1e5 + 5;
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

int lst[maxn];
int nxt[maxn];
int dp[maxn];

void solve() {
  {
    int k = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[k - 1]) {
        a[k++] = a[i];
      }
    }
    n = k;
  }
  for (int i = 1; i <= n; ++i) {
    lst[i] = -1;
  }
  for (int i = n - 1; i >= 0; --i) {
    nxt[i] = lst[a[i]];
    lst[a[i]] = i;
  }
  for (int i = 0; i <= n; ++i) {
    dp[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    auto cur = dp[i];
    dp[i + 1] = max(dp[i + 1], cur);
    if (i && nxt[i - 1] != -1) {
      auto &nx = dp[nxt[i - 1] + 1];
      nx = max(nx, cur + 1);
    }
    if (i <= 1 || nxt[i - 2] == -1) {
      continue;
    }
    {
      auto &nx = dp[nxt[i - 2] + 1];
      nx = max(nx, cur + 1);
    }
  }
  int res = n - dp[n];
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