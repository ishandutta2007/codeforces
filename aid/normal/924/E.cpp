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

const int maxn = (int) 1e4 + 5;
int n, l, r;
int a[maxn], b[maxn];

int read() {
  if (scanf("%d%d%d", &n, &l, &r) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
int sum[maxn];
int dp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(b[i], -a[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    a[i] = -tosort[i].second;
    b[i] = tosort[i].first;
  }
  sum[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  for (int i = 0; i <= sum[0]; i++) {
    dp[i] = -inf;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int x = sum[0]; x >= 0; x--) {
      auto &cur = dp[x];
      if (cur < 0) {
        continue;
      }
      if (x + a[i] <= sum[0]) {
        auto &nxt = dp[x + a[i]];
        nxt = max(nxt, cur + (b[i] && (l <= x && x <= r)));
      }
      int tox = x + sum[i] - a[i];
      if (b[i] && (l <= tox && tox <= r)) {
        cur++;
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= sum[0]; i++) {
    res = max(res, dp[i]);
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