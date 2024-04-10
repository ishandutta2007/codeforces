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
int a[maxn][4];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

vector<int> tosort;

void solve() {
  tosort.clear();
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i][0] + a[i][1] >= a[i][2] + a[i][3]) {
      res += a[i][0] - a[i][1];
      tosort.push_back(a[i][0] + a[i][1]);
      res += a[i][2] - a[i][3];
      tosort.push_back(a[i][2] + a[i][3]);
    } else if (a[i][0] >= a[i][3]) {
      res += 2 * (a[i][0] - a[i][3]);
    } else if (a[i][1] >= a[i][2]) {
      res += 2 * (a[i][2] - a[i][1]);
    }
  }
  sort(tosort.begin(), tosort.end(), greater<int>());
  for (int i = 0; i < sz(tosort); i++) {
    res += tosort[i] * ((i & 1) ? -1 : 1);
  }
  assert(!(res & 1));
  res /= 2;
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