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

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

int fen[maxn];

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

void add(int i, int val) {
  for (; i < n; i |= i + 1) {
    fen[i] += val;
  }
}

int getKth(int k) {
  int i = 0;
  for (int bit = 20; bit >= 0; bit--) {
    int x = i + (1 << bit) - 1;
    if (x >= n) {
      continue;
    }
    if (fen[x] <= k) {
      i += (1 << bit);
      k -= fen[x];
    }
  }
  return i;
}

void toFact(int a[maxn]) {
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int cur = a[i] - get(a[i]);
    add(a[i], 1);
    a[i] = cur;
  }
  reverse(a, a + n);
}

void addFact(int a[maxn], int b[maxn]) {
  int carry = 0;
  for (int i = 0; i < n; i++) {
    a[i] += b[i] + carry;
    carry = a[i] / (i + 1);
    a[i] %= (i + 1);
  }
}

void toPerm(int a[maxn]) {
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    add(i, 1);
  }
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    int cur = getKth(a[i]);
    add(cur, -1);
    a[i] = cur;
  }
}

void solve() {
  toFact(a);
  toFact(b);
  addFact(a, b);
  toPerm(a);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
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