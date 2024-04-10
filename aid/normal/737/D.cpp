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

const int maxn = 4010, maxk = 105;
int n;
int a[maxn];
int s[maxn];
int dp[maxn / 2][maxk][maxk];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  for (int l = n / 2; l >= 0; l--) {
    for (int k = 1; k + 2 < maxk; k++) {
      for (int dif = 0; dif + 1 < maxk; dif++) {
        int r = l + dif;
        if (l + r > n) {
          break;
        }
        if (l + k + r > n) {
          dp[l][k][dif] = s[l] - (s[n] - s[n - r]);
          continue;
        }
        dp[l][k][dif] = -inf;
        for (int i = k; i <= k + 1; i++) {
          if (l + i + r > n) {
            continue;
          }
          if (l + 2 * i + r > n) {
            dp[l][k][dif] = max(dp[l][k][dif], s[l + i] - (s[n] - s[n - r]));
            continue;
          }
          int cur = inf;
          for (int j = i; j <= i + 1; j++) {
            if (l + i + r + j > n) {
              continue;
            }
            cur = min(cur, dp[l + i][j][dif + j - i]);
          }
          dp[l][k][dif] = max(dp[l][k][dif], cur);
        }
      }
    }
  }
  printf("%d\n", dp[0][1][0]);
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