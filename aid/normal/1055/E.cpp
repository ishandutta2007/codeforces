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

const int maxn = 1505;
int n, s, m, k;
int a[maxn];
int ls[maxn], rs[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &s, &m, &k) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < s; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    ls[i]--;
  }
  return true;
}

vector<int> as;
int go[maxn];
int b[maxn];
int sum[maxn];
int dp[maxn][maxn];

int check(int mx) {
  for (int i = 0; i < n; i++) {
    b[i] = (a[i] >= mx);
  }
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + (1 - b[i]);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      auto cur = dp[i][j];
      if (cur >= inf) {
        continue;
      }
      dp[i + 1][j] = min(dp[i + 1][j], cur);
      if (!b[i] && go[i] != -1) {
        int ni = go[i];
        int nj = j + (sum[ni] - sum[i]);
        dp[ni][nj] = min(dp[ni][nj], cur + 1);
      }
    }
  }
  for (int i = k; i <= n; i++) {
    if (dp[n][i] <= m) {
      return true;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < n; i++) {
    as.push_back(a[i]);
  }
  sort(as.begin(), as.end());
  as.erase(unique(as.begin(), as.end()), as.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
  }
  for (int i = 0; i < n; i++) {
    go[i] = -1;
    for (int j = 0; j < s; j++) {
      if (ls[j] <= i && i < rs[j]) {
        go[i] = max(go[i], rs[j]);
      }
    }
  }
  int l = 0, r = sz(as);
  if (!check(r)) {
    printf("-1\n");
    return;
  }
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%d\n", as[l]);
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