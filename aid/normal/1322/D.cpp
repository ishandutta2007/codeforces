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

const int maxn = 4005;
int n, m;
int l[maxn];
int s[maxn];
int c[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    l[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  for (int i = 0; i < n + m; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

int add(int x, int cnt) {
  int res = c[x];
  while (cnt & 1) {
    cnt >>= 1;
    x++;
    res += c[x];
  }
  return res;
}

int prv[maxn][maxn];
int dp[maxn][maxn];
int dp1[maxn];

void solve() {
  for (int i = 0; i < m; i++) {
    prv[0][i] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      prv[i + 1][j] = (l[i] == j ? i : prv[i][j]);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -inf;
    }
  }
  for (int i = 0; i <= m; i++) {
    dp1[i] = -inf;
  }
  dp1[0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = l[i];
    for (int j = 0; j <= x; j++) {
      dp[i + 1][0] = max(dp[i + 1][0], dp1[j]);
    }
    for (int cnt = 0; cnt <= n; cnt++) {
      auto cur = dp[i + 1][cnt];
      if (cur <= -inf) {
        continue;
      }
      for (int take = 0; take < 2; take++) {
        auto val = cur;
        if (take) {
          val += add(x, cnt) - s[i];
        }
        int ncnt = cnt + take;
        int nx = x;
        while (ncnt > 0 && nx < m) {
          int j = prv[i][nx];
          if (j >= 0) {
            dp[j + 1][ncnt] = max(dp[j + 1][ncnt], val);
          }
          ncnt >>= 1;
          nx++;
        }
        dp1[nx] = max(dp1[nx], val);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= m; i++) {
    res = max(res, dp1[i]);
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