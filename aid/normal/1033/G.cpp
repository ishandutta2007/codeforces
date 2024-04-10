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

const int maxn = 105;
int n, m;
long long a[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long ans[4];

void solve() {
  for (int i = 0; i < 4; i++) {
    ans[i] = 0;
  }
  for (int s = 2; s <= 2 * m; s++) {
    int mn = max(0, s - m - 1);
    int d = mn;
    int g = 0;
    int mx0 = mn, mx1 = mn;
    for (int i = 0; i < n; i++) {
      int x = a[i] % s;
      if (2 * x < s) {
        d = max(d, x);
      } else {
        d = max(d, s - x - 1);
        g ^= 1;
        int half = x / 2;
        if (mx0 < half) {
          mx1 = mx0;
          mx0 = half;
        } else if (mx1 < half) {
          mx1 = half;
        }
      }
    }
    ans[0] += (d - mn);
    ans[1] += (d - mn);
    int l = d;
    if (mx1 > l) {
      ans[0] += (mx1 - l);
      ans[1] += (mx1 - l);
      l = mx1;
    }
    if (mx0 > l) {
      if (g) {
        ans[2] += (mx0 - l) * 2;
      } else {
        ans[0] += (mx0 - l);
        ans[1] += (mx0 - l);
      }
      l = mx0;
    }
    ans[3 ^ g] += (s / 2 - l) * 2;
    if (!(s & 1)) {
      ans[3 ^ g]--;
    }
  }
  for (int i = 0; i < 4; i++) {
    printf("%lld ", ans[i]);
  }
  printf("\n");
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