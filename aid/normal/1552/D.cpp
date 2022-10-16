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

const int maxn = 11;
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

void solve() {
  for (int msk0 = 0; msk0 < (1 << n); ++msk0) {
    int nmsk = (((1 << n) - 1) ^ msk0);
    for (int msk1 = nmsk; msk1 > 0; msk1 = ((msk1 - 1) & nmsk)) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (msk0 & (1 << i)) {
          sum += a[i];
        } else if (msk1 & (1 << i)) {
          sum -= a[i];
        }
      }
      if (sum == 0) {
        printf("YES\n");
        return;
      }
    }
  }
  printf("NO\n");
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