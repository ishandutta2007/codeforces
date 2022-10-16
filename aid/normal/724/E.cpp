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

const int maxn = (int) 1e4 + 5;
int n, c;
int p[maxn], s[maxn];

int read() {
  if (scanf("%d%d", &n, &c) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  return true;
}

long long dp_[2][maxn], *dp, *ndp;

void solve() {
  dp = dp_[0];
  ndp = dp_[1];
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i + 1; j++) {
      ndp[j] = infll;
    }
    for (int j = 0; j <= i; j++) {
      ndp[j] = min(ndp[j], dp[j] + p[i] + (long long) j * c);
      ndp[j + 1] = min(ndp[j + 1], dp[j] + s[i]);
    }
    swap(dp, ndp);
  }
  long long res = infll;
  for (int i = 0; i <= n; i++) {
    res = min(res, dp[i]);
  }
  printf("%lld\n", res);
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