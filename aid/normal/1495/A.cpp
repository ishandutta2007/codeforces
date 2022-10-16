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
vector<int> xs, ys;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  xs.clear();
  ys.clear();
  for (int i = 0; i < 2 * n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 0) {
      ys.push_back(abs(y));
    } else {
      xs.push_back(abs(x));
    }
  }
  return true;
}

void solve() {
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  ld res = 0;
  for (int i = 0; i < n; ++i) {
    res += sqrt((ld) ((long long) xs[i] * xs[i] + (long long) ys[i] * ys[i]));
  }
  printf("%.12f\n", (double) res);
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