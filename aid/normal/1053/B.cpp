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

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    a[i] = __builtin_popcountll(x);
  }
  return true;
}

const int maxs = 130;
int s[maxn];
int cnt[maxn][2];

void solve() {
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  cnt[n + 1][0] = 0;
  cnt[n + 1][1] = 0;
  for (int i = n; i >= 0; i--) {
    cnt[i][0] = cnt[i + 1][0];
    cnt[i][1] = cnt[i + 1][1];
    cnt[i][s[i] & 1]++;
  }
  long long res = 0;
  for (int l = 0; l < n; l++) {
    int cur = 0;
    int mx = 0;
    for (int r = l + 1; r <= n; r++) {
      cur += a[r - 1];
      mx = max(mx, a[r - 1]);
      if (cur >= maxs) {
        res += cnt[r][s[l] & 1];
        break;
      }
      if (2 * mx <= cur && !(cur & 1)) {
        res++;
      }
    }
  }
  printf("%lld\n", res);
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