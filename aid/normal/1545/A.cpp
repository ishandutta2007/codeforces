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
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

int fen[maxn];

void add(int i, int x) {
  for (; i < maxn; i |= i + 1) {
    fen[i] += x;
  }
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

int invs[maxn];
int odd[maxn];
int bal[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    invs[i] = i - get(a[i]);
    add(a[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    add(a[i], -1);
  }
  for (int i = n - 1; i >= 0; --i) {
    invs[i] += get(a[i] - 1);
    add(a[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    add(a[i], -1);
  }
  for (int i = 0; i < n; ++i) {
    odd[a[i]] ^= 1;
    if (!(invs[i] & 1)) {
      continue;
    }
    int sgn = 1 - 2 * odd[a[i]];
    bal[a[i]] += sgn;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (bal[a[i]]) {
      ok = false;
    }
    bal[a[i]] = 0;
    odd[a[i]] = 0;
  }
  if (ok) {
    printf("YES\n");
  } else {
    printf("NO\n");
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