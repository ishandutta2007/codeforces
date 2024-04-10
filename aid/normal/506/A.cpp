#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int N = 30001;
int d;
int a[N];

bool read() {
  int n;
  if (scanf("%d%d", &n, &d) < 2) {
    return false;
  }
  for (int i = 0; i < N; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  return true;
}

vector<pair<int, int>> dp[N];

void solve() {
  for (int i = 0; i < N; i++) {
    dp[i].clear();
  }
  dp[d].push_back(make_pair(d, a[d]));
  int res = 0;
  for (int x = d; x < N; x++) {
    sort(dp[x].begin(), dp[x].end());
    if (!dp[x].empty()) {
      int k = 1;
      for (int i = 1; i < sz(dp[x]); i++) {
        if (dp[x][i].first != dp[x][k - 1].first) {
          dp[x][k] = dp[x][i];
          k++;
          continue;
        }
        dp[x][k - 1].second = max(dp[x][k - 1].second, dp[x][i].second);
      }
      dp[x].resize(k);
    }
    for (int i = 0; i < sz(dp[x]); i++) {
      int l = dp[x][i].first, cur = dp[x][i].second;
      res = max(res, cur);
      for (int dl = -1; dl <= 1; dl++) {
        int nl = l + dl;
        if (nl <= 0 || x + nl >= N) {
          continue;
        }
        int nx = x + nl;
        dp[nx].push_back(make_pair(nl, cur + a[nx]));
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}