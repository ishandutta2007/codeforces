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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int bal[maxn];
int bad, odd;
int l, r;
int l1, r1;
int x, y;

void add(int cur, int val) {
  if (bal[cur] < 0) {
    bad--;
  }
  if (bal[cur] & 1) {
    odd--;
  }
  bal[cur] += val;
  if (bal[cur] < 0) {
    bad++;
  }
  if (bal[cur] & 1) {
    odd++;
  }
}

void fix() {
  int nl1 = n - r - 1, nr1 = n - l - 1;
  {
    int a = max(l, nl1), b = min(r, nr1);
    if (a <= b) {
      if (a == nl1) {
        nl1 = b + 1;
      } else {
        assert(b == nr1);
        nr1 = a - 1;
      }
    }
  }
  while (l1 != nl1 || r1 != nr1) {
    if (l1 > nl1) {
      l1--;
      add(a[l1], -1);
      continue;
    }
    if (r1 < nr1) {
      r1++;
      add(a[r1], -1);
      continue;
    }
    if (l1 < nl1) {
      add(a[l1], 1);
      l1++;
      continue;
    }
    if (r1 > nr1) {
      add(a[r1], 1);
      r1--;
      continue;
    }
  }
}

void gol() {
  add(a[l], -1);
  l++;
  fix();
}

void gor() {
  r++;
  add(a[r], 1);
  fix();
}

bool check() {
  if (bad) {
    return false;
  }
  if (odd > (n & 1)) {
    return false;
  }
  {
    int needx = min(l, n - r - 1);
    if (x < needx) {
      return false;
    }
  }
  if (r < n / 2) {
    if (y > r) {
      return false;
    }
  } else if (l > n / 2) {
    if (y > n - l - 1) {
      return false;
    }
  }
  return true;
}

void solve() {
  {
    x = 0;
    while (x < n && a[x] == a[n - x - 1]) {
      x++;
    }
    y = n / 2 - 1;
    while (y >= 0 && a[y] == a[n - y - 1]) {
      y--;
    }
  }
  for (int i = 0; i < n; i++) {
    bal[i] = 0;
  }
  bad = 0;
  odd = 0;
  long long res = 0;
  for (l = 0, r = -1, l1 = n, r1 = n - 1; l < n; gol()) {
    while (r < l) {
      gor();
    }
    while (r < n - 1 && !check()) {
      gor();
    }
    if (check()) {
      res += n - r;
    }
  }
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