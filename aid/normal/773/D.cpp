#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

const int maxn = 2200;
int n;
int g[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      scanf("%d", g[i] + j);
      g[j][i] = g[i][j];
    }
  }
  return true;
}

ll dist[maxn];
int used[maxn];

void solve() {
  ll toadd = 0;
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (g[a][b] > g[i][j]) {
        a = i, b = j;
      }
    }
  }
  toadd = g[a][b];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      g[i][j] -= toadd;
    }
  }
  toadd *= n - 1;
  for (int i = 0; i < n; i++) {
    dist[i] = 1e18;
    used[i] = false;
  }
  int c[2];
  c[0] = a;
  c[1] = b;
  for (int it = 0; it < 2; it++) {
    int v = c[it];
    dist[v] = 0;
    for (int i = 0; i < n; i++) {
      if (i == v || i == c[!it]) {
        continue;
      }
      dist[i] = min(dist[i], (ll) g[v][i]);
      for (int j = 0; j < n; j++) {
        if (j == v || j == i) {
          continue;
        }
        dist[j] = min(dist[j], (ll) min(g[v][i], g[i][j]) + g[i][j]);
      }
    }
  }
  for (int it = 0; it < n; it++) {
    int mn = -1;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      if (mn == -1 || dist[mn] > dist[i]) {
        mn = i;
      }
    }
    assert(mn >= 0);
    used[mn] = 1;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      ll ndist = dist[mn] + g[mn][i];
      if (ndist < dist[i]) {
        dist[i] = ndist;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld\n", dist[i] + toadd);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}