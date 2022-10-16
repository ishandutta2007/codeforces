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

const int maxk = 20, powk = (1 << maxk);
int n, k;
int x[powk];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  return true;
}

const int maxvs = powk * (maxk + 5);
int go[maxvs][2];
int vs;
int a[powk], b[powk], c[powk];
int ans[powk];

int newNode() {
  go[vs][0] = -1;
  go[vs][1] = -1;
  return vs++;
}

void add(int x, int k) {
  int v = 0;
  for (int i = k - 1; i >= 0; --i) {
    int d = ((x >> i) & 1);
    if (go[v][d] == -1) {
      go[v][d] = newNode();
    }
    v = go[v][d];
  }
}

int getMin(int v, int x, int y, int i) {
  if (i < 0) {
    return x;
  }
  int d = ((y >> i) & 1);
  if (go[v][d] != -1) {
    return getMin(go[v][d], x, y, i - 1);
  }
  return getMin(go[v][!d], x ^ (1 << i), y, i - 1);
}

int getMax(int v, int x, int y, int i) {
  if (i < 0) {
    return x;
  }
  int d = ((y >> i) & 1);
  if (go[v][!d] != -1) {
    return getMax(go[v][!d], x ^ (1 << i), y, i - 1);
  }
  return getMax(go[v][d], x, y, i - 1);
}

void solve1(int k) {
  vs = 0;
  newNode();
  for (int i = 0; i < (1 << k); ++i) {
    if (b[i]) {
      add(i, k);
    }
  }
  if (go[0][0] == -1 || go[0][1] == -1) {
    return;
  }
  for (int i = 0; i < (1 << k); ++i) {
    int v = go[0][0], u = go[0][1];
    if (i & (1 << (k - 1))) {
      swap(v, u);
    }
    int res = getMin(u, (1 << (k - 1)), i, k - 2) - getMax(v, 0, i, k - 2);
    c[i] = min(c[i], res);
  }
}

void solve() {
  for (int i = 0; i < (1 << k); ++i) {
    a[i] = false;
    ans[i] = inf;
  }
  for (int i = 0; i < n; ++i) {
    a[x[i]] = true;
  }
  for (int l = 0; l < k; ++l) {
    for (int i = 0; i < (1 << (k - l)); ++i) {
      c[i] = inf;
    }
    for (int i = 0; i < (1 << l); ++i) {
      for (int j = 0; j < (1 << (k - l)); ++j) {
        b[j] = a[(i << (k - l)) ^ j];
      }
      solve1(k - l);
    }
    for (int i = 0; i < (1 << l); ++i) {
      for (int j = 0; j < (1 << (k - l)); ++j) {
        auto &cur = ans[(i << (k - l)) ^ j];
        cur = min(cur, c[j]);
      }
    }
  }
  for (int i = 0; i < (1 << k); ++i) {
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}