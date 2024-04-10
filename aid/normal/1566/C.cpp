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
char a[2][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2; ++i) {
    scanf("%s", a[i]);
    for (int j = 0; j < n; ++j) {
      a[i][j] -= '0';
    }
  }
  return true;
}

void solve() {
  int res = 0;
  int cur = 0;
  for (int i = 0; i < n;) {
    for (int j = 0; j < 2; ++j) {
      cur |= (1 << a[j][i]);
    }
    if (cur == 3) {
      cur = 0;
      res += 2;
      ++i;
      continue;
    }
    if (cur == 2) {
      ++i;
      continue;
    }
    if (i + 1 < n && a[0][i + 1] == 1 && a[1][i + 1] == 1) {
      cur = 0;
      res += 2;
      i += 2;
      continue;
    }
    cur = 0;
    ++res;
    ++i;
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