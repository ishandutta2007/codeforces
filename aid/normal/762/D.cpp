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
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn][3];
long long dp[maxn][5];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j][i]);
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = -infll;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    long long allsum = 0;
    for (int k = 0; k < 3; k++) {
      allsum += a[i][k];
    }
    for (int j = 0; j < 5; j++) {
      if (dp[i][j] == -infll) {
        continue;
      }
      if (j < 3) {
        for (int toj = 0; toj < 3; toj++) {
          long long sum = 0;
          int l = j, r = toj;
          if (l > r) {
            swap(l, r);
          }
          for (int k = l; k <= r; k++) {
            sum += a[i][k];
          }
          dp[i + 1][toj] = max(dp[i + 1][toj], dp[i][j] + sum);
        }
        if (j == 1) {
          continue;
        }
        int toj = (j ? 4 : 3);
        dp[i + 1][toj] = max(dp[i + 1][toj], dp[i][j] + allsum);
        continue;
      }
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + allsum);
      int toj = (j == 3 ? 2 : 0);
      dp[i + 1][toj] = max(dp[i + 1][toj], dp[i][j] + allsum);
    }
  }
  printf("%lld\n", dp[n][2]);
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