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

const int maxn = (int) 1e6 + 5, maxb = 21, maxx = (1 << maxb) + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int cnt[maxx];

void add(int x, int b) {
  if (cnt[x] >= 2) {
    return;
  }
  cnt[x]++;
  while (b < maxb) {
    if (x & (1 << b)) {
      add(x ^ (1 << b), b + 1);
    }
    b++;
  }
}

void solve() {
  for (int i = 0; i < maxx; i++) {
    cnt[i] = 0;
  }
  int res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int cur = 0;
    for (int b = maxb - 1; b >= 0; b--) {
      if (a[i] & (1 << b)) {
        continue;
      }
      if (cnt[cur ^ (1 << b)] >= 2) {
        cur ^= (1 << b);
      }
    }
    if (cnt[cur] >= 2) {
      res = max(res, (a[i] | cur));
    }
    add(a[i], 0);
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