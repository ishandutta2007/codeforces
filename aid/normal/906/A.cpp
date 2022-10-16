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

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

const int sigma = 26;
char tmp[maxn];

void solve() {
  int msk = (1 << sigma) - 1;
  bool ok = false;
  int res = 0;
  for (int it = 0; it < n; it++) {
    scanf("%s", tmp);
    char c = tmp[0];
    if (ok && (c == '!' || (c == '?' && it < n - 1))) {
      res++;
    }
    scanf("%s", tmp);
    if (c == '.' || c == '!') {
      string s = tmp;
      int cur = 0;
      for (int i = 0; i < sz(s); i++) {
        cur |= (1 << (s[i] - 'a'));
      }
      if (c == '!') {
        msk &= cur;
      } else {
        msk &= (((1 << sigma) - 1) ^ cur);
      }
    } else {
      char a = tmp[0];
      if (it < n - 1) {
        msk &= (((1 << sigma) - 1) ^ (1 << (a - 'a')));
      }
    }
    if (__builtin_popcount(msk) == 1) {
      ok = true;
    }
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