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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e6 + 5;
int n;
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int fen[maxn];

void add(int i, int x) {
  for (; i < n; i |= i + 1) {
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

long long getInvs() {
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    res += get(p[i]);
    add(p[i], 1);
  }
  return res;
}

void solve() {
  long long invs = getInvs();
  if ((invs & 1) == ((3 * n) & 1)) {
    printf("Petr\n");
  } else {
    printf("Um_nik\n");
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