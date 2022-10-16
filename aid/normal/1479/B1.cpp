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
  int res = 0;
  int lst = -1;
  int cnt = 0;
  bool ok = true;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && a[j] == a[i]) {
      ++j;
    }
    if (j - i == 1) {
      ++res;
      if (a[i] != lst) {
        ++cnt;
      } else {
        cnt = 0;
      }
      if (cnt >= 2) {
        ok = true;
      }
      continue;
    }
    if (a[i] != lst) {
      ok = true;
    }
    if (ok) {
      res += 2;
    } else {
      ++res;
    }
    lst = a[i];
    ok = false;
    cnt = 0;
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