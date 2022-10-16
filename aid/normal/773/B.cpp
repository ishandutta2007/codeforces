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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 130, m = 5, l = 6;
int n;
int a[maxn][m];
int x[m];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    x[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] != -1) {
        x[j]++;
      }
    }
  }
  return true;
}

int res;
int b[m];
int s[2];

bool check(int k) {
  for (int i = 0; i < m; i++) {
    if (a[0][i] >= 0) {
      continue;
    }
    for (int j = l; j >= 1; j--) {
      if (x[i] * (1 << (j - 1)) <= n + k) {
        b[i] = j;
        break;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    s[i] = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] != -1) {
        s[i] += b[j] * 2 * (250 - a[i][j]);
      }
    }
  }
  return s[0] > s[1];
}

void rec(int pos, int k) {
  if (k >= res) {
    return;
  }
  if (pos == m) {
    if (check(k)) {
      /*for (int i = 0; i < m; i++) {
        eprintf("%d ", b[i]);
      }
      eprintf("\n%d\n", k);*/
      res = k;
    }
    return;
  }
  if (a[0][pos] == -1) {
    rec(pos + 1, k);
  }
  for (int i = 1; i <= l; i++) {
    b[pos] = i;
    int q = (1 << i);
    int nk = k;
    if (i < l && x[pos] * q <= n) {
      if (a[0][pos] == -1) {
        continue;
      }
      nk = max(nk, (n - x[pos] * q) / (q - 1) + 1);
    } else if (x[pos] * (q >> 1) > n) {
      nk = max(nk, x[pos] * (q >> 1) - n);
    }
    rec(pos + 1, nk);
  }
}

void solve() {
  res = (int) 1e9 + 8;
  rec(0, 0);
  if (res >= (int) 1e9 + 8) {
    res = -1;
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