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

const int maxn = 105;
int n, m, k;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

int need[maxn];
char ans[maxn][maxn];

char toChar(int x) {
  if (x < 10) {
    return (char) ('0' + x);
  }
  x -= 10;
  if (x < 26) {
    return (char) ('a' + x);
  }
  x -= 26;
  return (char) ('A' + x);
}

void solve() {
  {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == 'R') {
          cnt++;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      need[i] = cnt / k;
    }
    cnt %= k;
    for (int i = 0; i < cnt; i++) {
      need[i]++;
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    for (int jj = 0; jj < m; jj++) {
      int j = (!(i & 1) ? jj : m - 1 - jj);
      ans[i][j] = toChar(cur);
      if (c[i][j] == 'R') {
        need[cur]--;
        if (!need[cur] && cur + 1 < k) {
          cur++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i][m] = 0;
    printf("%s\n", ans[i]);
  }
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