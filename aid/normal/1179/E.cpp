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

const int maxn = 1005;
int n;
long long s;

bool read() {
  if (scanf("%d%lld", &n, &s) < 2) {
    return false;
  }
  return true;
}

const long long X = (long long) 1e18;

int p[maxn];
long long vals[maxn];
long long ls[maxn], rs[maxn];

long long ask(int i, long long x) {
  printf("? %d %lld\n", i + 1, x);
  fflush(stdout);
  long long res;
  scanf("%lld", &res);
  return res;
}

long long get(int i, int k) {
  long long y = s / n * k;
  long long l = 0, r = X;
  while (l < r - 1) {
    long long m = (l + r) / 2;
    if (ask(p[i], m) < y) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}

long long getKth(int l, int m, int r) {
  if (l == r - 1) {
    return get(l, l);
  }
  int k = l + rnd(r - l);
  long long x = get(k, m);
  long long y = s / n * m;
  int m0 = l, m1 = l;
  for (int i = l; i < r; i++) {
    vals[i] = ask(p[i], x);
    if (vals[i] > y) {
      swap(p[i], p[m0]);
      swap(vals[i], vals[m0]);
      if (m1 == m0) {
        m1++;
      }
      m0++;
    }
    if (vals[i] == y) {
      swap(p[i], p[m1]);
      swap(vals[i], vals[m1]);
      m1++;
    }
  }
  if (m0 <= m && m < m1) {
    return x;
  }
  if (m < m0) {
    return getKth(l, m, m0);
  } else {
    return getKth(m1, m, r);
  }
}

void rec(int l, int r, long long lx, long long rx) {
  if (l == r - 1) {
    ls[p[l]] = lx;
    rs[p[l]] = rx;
    return;
  }
  int m = (l + r) / 2;
  long long mx = getKth(l, m, r);
  rec(l, m, lx, mx);
  rec(m, r, mx, rx);
}

void solve() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  rec(0, n, 0, X);
  printf("!\n");
  for (int i = 0; i < n; i++) {
    printf("%lld %lld\n", ls[i], rs[i]);
  }
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}