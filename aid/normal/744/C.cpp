#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 17, maxs = maxn * maxn, pown = (1 << maxn);
int n;
char c[maxn];
int r[maxn], b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf(" %c%d%d", &c[i], &r[i], &b[i]);
  }
  return true;
}

int dp[pown][maxs];

void solve() {
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < maxs; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < maxs; j++) {
      if (dp[i][j] <= -inf) {
        continue;
      }
      int rcnt = 0, bcnt = 0;
      for (int k = 0; k < n; k++) {
        if (i & (1 << k)) {
          if (c[k] == 'R') {
            rcnt++;
          } else {
            bcnt++;
          }
        }
      }
      for (int k = 0; k < n; k++) {
        if (!(i & (1 << k))) {
          int sr = r[k] - max(r[k] - rcnt, 0), sb = b[k] - max(b[k] - bcnt, 0);
          dp[i | (1 << k)][j + sr] = max(dp[i | (1 << k)][j + sr], dp[i][j] + sb);
        }
      }
    }
  }
  int rsum = 0, bsum = 0;
  for (int i = 0; i < n; i++) {
    rsum += r[i];
    bsum += b[i];
  }
  int res = max(rsum, bsum);
  for (int i = 0; i < maxs; i++) {
    if (dp[(1 << n) - 1][i] > -inf) {
      res = min(res, max(rsum - i, bsum - dp[(1 << n) - 1][i]));
    }
  }
  res += n;
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}