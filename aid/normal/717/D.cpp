#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 205;
int n, k;
ld p[2 * maxn];
ld a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

int read() {
  if (scanf("%d%d", &k, &n) < 2) {
    return false;
  }
  for (int i = 0; i < 2 * maxn; i++) {
    p[i] = 0;
  }
  n++;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
  }
  return true;
}

void matPow(int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i][j] = (i == j);
    }
  }
  while (k) {
    if (k & 1) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          c[i][j] = 0;
          for (int l = 0; l < n; l++) {
            c[i][j] += a[i][l] * b[l][j];
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = c[i][j];
        }
      }
    }
    k >>= 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[i][j] = 0;
        for (int l = 0; l < n; l++) {
          c[i][j] += a[i][l] * a[l][j];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = c[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = b[i][j];
    }
  }
}

void solve() {
  int nn = 1;
  while (nn < n) {
    nn <<= 1;
  }
  n = nn;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = p[i ^ j];
    }
  }
  matPow(k);
  printf("%.12lf\n", 1 - a[0][0]);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}