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

const int maxn = 55, maxq = maxn * 100;
int n;
long long as[maxn];
int bs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &as[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &bs[i]);
  }
  return true;
}

pair<long long, int> tosort[maxn];
long long dp[maxn][maxn][maxq];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(as[i], bs[i]);
  }
  sort(tosort, tosort + n, greater<pair<long long, int>>());
  for (int i = 0; i < n; i++) {
    as[i] = tosort[i].first;
    bs[i] = tosort[i].second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < maxq; k++) {
        dp[i][j][k] = infll;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int it = 0; it < n; it++) {
    for (int i = 0; i <= it; i++) {
      for (int j = it - i; j >= 0; j--) {
        for (int k = 0; k < maxq; k++) {
          auto &cur = dp[i][j][k];
          if (cur >= infll) {
            continue;
          }
          {
            int ni = i, nj = j + 1, nk = k + bs[it];
            auto &nxt = dp[ni][nj][nk];
            nxt = min(nxt, cur + as[it]);
          }
          if (i) {
            int ni = i - 1, nj = j, nk = k;
            auto &nxt = dp[ni][nj][nk];
            nxt = min(nxt, cur);
          }
          cur = infll;
        }
      }
    }
    if (it + 1 == n || as[it] != as[it + 1]) {
      for (int i = 0; i <= it + 1; i++) {
        for (int j = 1; i + j <= it + 1; j++) {
          for (int k = 0; k < maxq; k++) {
            auto &cur = dp[i][j][k];
            if (cur >= infll) {
              continue;
            }
            auto &nxt = dp[i + j][0][k];
            nxt = min(cur, nxt);
            cur = infll;
          }
        }
      }
    }
  }
  long long res = infll;
  for (int i = 0; i <= n; i++) {
    for (int k = 1; k < maxq; k++) {
      auto cur = dp[i][0][k];
      if (cur >= infll) {
        continue;
      }
      res = min(res, (cur * 1000 + k - 1) / k);
    }
  }
  printf("%lld\n", res);
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