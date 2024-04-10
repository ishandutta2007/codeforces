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

int a, b;

bool read() {
  if (scanf("%d%d", &a, &b) < 2) {
    return false;
  }
  return true;
}

vector<int> good, ans;

void solve() {
  int n = a + b;
  good.clear();
  good.resize(n + 1);
  for (int it = 0; it < 2; ++it) {
    int x = n / 2, y = n - x;
    if (it) {
      swap(x, y);
    }
    int l = abs(a - x);
    int r;
    if (a <= y) {
      r = x + a;
    } else {
      r = n - (a - y);
    }
    for (int i = l; i <= r; i += 2) {
      good[i] = true;
    }
  }
  ans.clear();
  for (int i = 0; i <= n; ++i) {
    if (good[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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