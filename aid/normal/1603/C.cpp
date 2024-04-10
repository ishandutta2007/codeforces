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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<pair<int, int>> dp, ndp;

void solve() {
  dp.clear();
  dp.push_back(make_pair(a[n - 1], 1));
  int res = 0;
  for (int i = n - 2; i >= 0; --i) {
    ndp.clear();
    for (int j = 0; j < sz(dp); ++j) {
      int x = dp[j].first, cnt = dp[j].second;
      int k = (a[i] + x - 1) / x;
      int y = a[i] / k;
      ndp.push_back(make_pair(y, cnt));
      add(res, mul(k - 1, mul(i + 1, cnt)));
    }
    ndp.push_back(make_pair(a[i], 1));
    swap(dp, ndp);
    int k = 0;
    for (int j = 1; j < sz(dp); ++j) {
      if (dp[j].first == dp[k].first) {
        dp[k].second += dp[j].second;
      } else {
        dp[++k] = dp[j];
      }
    }
    dp.resize(++k);
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