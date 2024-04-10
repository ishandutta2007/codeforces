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

const int maxn = (int) 2e5 + 5;
int n, m;
long long a[maxn];
long long ls[maxn], rs[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lld%lld", &ls[i], &rs[i]);
  }
  return true;
}

vector<pair<long long, long long>> s[maxn];
long long dp[maxn][2];

void solve() {
  sort(a, a + n);
  for (int i = 0; i <= n; ++i) {
    s[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int l = ls[i], r = rs[i];
    int p = lower_bound(a, a + n, l) - a;
    if (p < n && a[p] <= r) {
      continue;
    }
    s[p].push_back(make_pair(l, r));
  }
  for (int i = 0; i <= n; ++i) {
    sort(s[i].begin(), s[i].end());
  }
  {
    long long l = a[0];
    for (int i = 0; i < sz(s[0]); ++i) {
      l = min(l, s[0][i].second);
    }
    long long ld = a[0] - l;
    dp[0][0] = ld;
    dp[0][1] = 2 * ld;
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int aa = 0; aa < 2; ++aa) {
      auto &cur = dp[i + 1][aa];
      cur = infll;
      for (int b = 0; b < 2; ++b) {
        long long l = a[i + 1];
        for (int j = sz(s[i + 1]) - 1; j >= 0; --j) {
          long long r = s[i + 1][j].first;
          cur = min(cur, dp[i][!b] + (1 + b) * (r - a[i]) + (1 + aa) * (a[i + 1] - l));
          l = min(l, s[i + 1][j].second);
        }
        {
          long long r = a[i];
          cur = min(cur, dp[i][!b] + (1 + b) * (r - a[i]) + (1 + aa) * (a[i + 1] - l));
        }
      }
    }
  }
  long long res = infll;
  {
    long long r = a[n - 1];
    for (int i = 0; i < sz(s[n]); ++i) {
      r = max(r, s[n][i].first);
    }
    long long rd = r - a[n - 1];
    res = min(dp[n - 1][0] + 2 * rd, dp[n - 1][1] + rd);
  }
  printf("%lld\n", res);
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