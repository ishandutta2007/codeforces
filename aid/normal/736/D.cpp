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

const int maxn = 2005;
int n, m;
int a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x][y] = i;
  }
  return true;
}

int ans[maxn * maxn];
bitset<maxn> b[maxn];
bitset<maxn> c[maxn];
int p[maxn];

void solve() {
  for (int i = 0; i < m; i++) {
    ans[i] = true;
  }
  for (int i = 0; i < n; i++) {
    b[i].reset();
    for (int j = 0; j < n; j++) {
      if (a[i][j] != -1) {
        b[i][j] = true;
      }
    }
    c[i].reset();
    c[i][i] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (b[i][p[j]]) {
        b[i] ^= b[j];
        c[i] ^= c[j];
      }
    }
    p[i] = 0;
    while (!b[i][p[i]]) {
      p[i]++;
    }
    for (int j = 0; j < i; j++) {
      if (b[j][p[i]]) {
        b[j] ^= b[i];
        c[j] ^= c[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i][j] && a[j][p[i]] != -1) {
        ans[a[j][p[i]]] = false;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    printf(ans[i] ? "YES\n" : "NO\n");
  }
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