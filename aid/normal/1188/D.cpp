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

const int maxn = (int) 1e5 + 5;
int n;
long long a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

const int maxb = 60;
pair<long long, int> b[maxn], c[maxn];
int dp[maxn], ndp[maxn];
int cnt[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    dp[i] = i;
  }
  dp[n] = 0;
  for (int i = 0; i < n; i++) {
    c[i] = make_pair(a[i], i);
  }
  sort(c, c + n);
  for (int bit = maxb - 1; bit >= 0; bit--) {
    for (int i = 0; i < n; i++) {
      b[i] = make_pair((a[i] & ((1ll << bit) - 1)), i);
    }
    sort(b, b + n);
    cnt[0] = 0;
    for (int i = 0; i < n; i++) {
      int id = b[i].second;
      cnt[i + 1] = cnt[i] + ((a[id] >> bit) & 1);
    }
    b[n].first = (1ll << bit);
    for (int i = 0; i <= n; i++) {
      int x = cnt[i] + ((n - i) - (cnt[n] - cnt[i]));
      int j = lower_bound(c, c + n, make_pair(b[i].first, -1)) - c;
      ndp[i] = dp[j] + x;
      j = lower_bound(c, c + n, make_pair(b[i].first + (1ll << bit), -1)) - c;
      ndp[i] = min(ndp[i], dp[j] + n - x);
    }
    swap(b, c);
    swap(dp, ndp);
  }
  printf("%d\n", dp[n]);
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