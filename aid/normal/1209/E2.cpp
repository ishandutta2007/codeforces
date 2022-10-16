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

const int maxn = 12, maxm = 2005;
int n, m;
int a[maxn][maxm];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

const int pown = (1 << maxn);
pair<int, int> tosort[maxm];
int b[maxn][maxn];
int dp[pown], dp1[pown], ndp[pown];

void solve() {
  for (int j = 0; j < m; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur = max(cur, a[i][j]);
    }
    tosort[j] = make_pair(cur, j);
  }
  sort(tosort, tosort + m, greater<pair<int, int>>());
  {
    int mm = min(n, m);
    for (int it = 0; it < mm; it++) {
      int j = tosort[it].second;
      for (int i = 0; i < n; i++) {
        b[it][i] = a[i][j];
      }
    }
    m = mm;
  }
  memset(dp, 0, sizeof(dp));
  for (int it = 0; it < m; it++) {
    memset(ndp, 0, sizeof(ndp));
    for (int sh = 0; sh < n; sh++) {
      for (int i = 0; i < (1 << n); i++) {
        dp1[i] = dp[i];
      }
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < (1 << n); i++) {
          if (!(i & (1 << j))) {
            dp1[i | (1 << j)] = max(dp1[i | (1 << j)], dp1[i] + b[it][(sh + j) % n]);
          }
        }
      }
      for (int i = 0; i < (1 << n); i++) {
        ndp[i] = max(ndp[i], dp1[i]);
      }
    }
    swap(dp, ndp);
  }
  printf("%d\n", dp[(1 << n) - 1]);
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