#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef double ld;

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

const int maxn = 105, maxm = 1005;
int n;
ld c, t;
int a[maxn], p[maxn];

bool read() {
  if (scanf("%d%lf%lf", &n, &c, &t) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &p[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
ld dp[maxn][maxm];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(a[i], p[i]);
  }
  sort(tosort, tosort + n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    a[i] = tosort[i].first;
    p[i] = tosort[i].second;
    sum += p[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = infll;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      for (int k = 0; k <= sum; k++) {
        auto cur = dp[j][k];
        if (cur > infll / 2) {
          continue;
        }
        auto &nxt = dp[j + 1][k + p[i]];
        nxt = min(nxt, (cur + a[i]) / 0.9);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      auto cur = dp[i][j];
      if (cur > infll / 2) {
        continue;
      }
      ld curt = sqrt(cur * c) - 1;
      curt = max(curt, (ld) 0);
      cur = curt / c + 10 * i + cur / (1 + curt);
      if (cur < t + eps) {
        res = max(res, j);
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}