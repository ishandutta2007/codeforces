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

const int maxn = (int) 2e5 + 5, k = 400, maxb = (maxn + k) / k;
int n, m;
int x[maxn], y[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  return true;
}

int cnt[k + 1][k + 1];
int added[maxn];

int a[maxn];
int s[maxb];

void update(int i, int val) {
  a[i] += val;
  s[i / k] += val;
}

void add(int i, int sgn) {
  int p = x[i] + y[i];
  if (p < k) {
    for (int t = 0; t < y[i]; ++t) {
      int tt = (added[i] + x[i] + t) % p;
      cnt[p][tt] += sgn;
    }
  } else {
    for (int t = added[i] + x[i]; t < m; t += p) {
      update(t, sgn);
      if (t + y[i] < m) {
        update(t + y[i], -sgn);
      }
    }
  }
}

int get(int t) {
  int res = 0;
  for (int p = 1; p < k; ++p) {
    res += cnt[p][t % p];
  }
  int tb = t / k;
  for (int b = 0; b < tb; ++b) {
    res += s[b];
  }
  for (int i = tb * k; i <= t; ++i) {
    res += a[i];
  }
  return res;
}

void solve() {
  for (int i = 1; i < k; ++i) {
    for (int j = 0; j < i; ++j) {
      cnt[i][j] = 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    a[i] = 0;
  }
  for (int i = 0; i < maxb; ++i) {
    s[i] = 0;
  }
  for (int q = 0; q < m; ++q) {
    int t, i;
    scanf("%d%d", &t, &i);
    --i;
    if (t == 1) {
      added[i] = q;
      add(i, 1);
    } else {
      add(i, -1);
    }
    printf("%d\n", get(q));
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