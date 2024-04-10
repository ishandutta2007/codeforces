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

const int maxn = 305;
int n, m;
int a[maxn * maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n * m; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

pair<int, int> tosort[maxn * maxn];
int c[maxn][maxn];

void solve() {
  for (int i = 0; i < n * m; ++i) {
    tosort[i] = make_pair(a[i], i);
  }
  sort(tosort, tosort + n * m);
  for (int j = 0; j < n * m;) {
    int i = j;
    while (j < n * m && tosort[j].first == tosort[i].first) {
      ++j;
    }
    for (int l = i; l < j;) {
      int r = min(j, (l / m + 1) * m);
      reverse(tosort + l, tosort + r);
      for (int k = l; k < r; ++k) {
        c[k / m][k % m] = tosort[k].second;
      }
      l = r;
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < j; ++k) {
        res += (c[i][k] < c[i][j]);
      }
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