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
int a[maxn], c[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &c[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
int mx[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    tosort[i] = make_pair(a[i], c[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; ++i) {
    a[i] = tosort[i].first;
    c[i] = tosort[i].second;
  }
  mx[0] = 0;
  for (int i = 0; i < n; ++i) {
    mx[i + 1] = max(mx[i], a[i] + c[i]);
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += c[i];
  }
  int r = 1;
  while (r < n) {
    int x = mx[r];
    int nr = upper_bound(a, a + n, x) - a;
    if (nr == r) {
      res += a[r] - x;
      ++r;
    } else {
      r = nr;
    }
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