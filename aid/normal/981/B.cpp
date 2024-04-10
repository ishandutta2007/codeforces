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

map<int, int> mp;

int read() {
  mp.clear();
  for (int it = 0; it < 2; it++) {
    int n;
    if (scanf("%d", &n) < 1) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      int a, x;
      scanf("%d%d", &a, &x);
      auto &cur = mp[a];
      cur = max(cur, x);
    }
  }
  return true;
}

void solve() {
  long long res = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    res += it->second;
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