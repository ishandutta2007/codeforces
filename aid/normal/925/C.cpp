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

const int maxn = (int) 1e5 + 5;
int n;
long long b[maxn];
int h[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
  }
  return true;
}

const int maxb = 61;

void solve() {
  for (int i = 0; i < n; i++) {
    h[i] = 63 - __builtin_clzll(b[i]);
  }
  list<long long> ans;
  for (int bit = maxb - 1; bit >= 0; bit--) {
    auto it = ans.begin();
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (h[i] == bit) {
        if (!ok) {
          printf("No\n");
          return;
        }
        ans.insert(it, b[i]);
        while (it != ans.end() && !(*it & (1ll << bit))) {
          it++;
        }
        if (it == ans.end()) {
          ok = false;
        } else {
          it++;
        }
      }
    }
  }
  printf("Yes\n");
  for (auto it = ans.begin(); it != ans.end(); it++) {
    printf("%lld ", *it);
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