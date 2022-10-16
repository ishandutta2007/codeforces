#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

int n, k;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

const int maxn = (int) 1e6 + 5;
int fen[maxn];

void add(int x, int val) {
  for (; x < n; x |= (x + 1)) {
    fen[x] += val;
  }
}

int get(int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    res += fen[x];
  }
  return res;
}

void solve() {
  k = min(k, n - k);
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  int x = 0;
  long long res = 1;
  for (int i = 0; i < n; i++) {
    int l = x, r = x + k - 1;
    if (r < n) {
      res += get(r) - get(l) + 1;
    } else {
      res += get(n - 1) - get(l);
      res += get(r - n);
      res++;
    }
    printf("%lld ", res);
    add(x, 1);
    x = (x + k) % n;
    add(x, 1);
  }
  printf("\n");
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
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}