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
int n, q;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int ans0[maxn][2];
deque<int> b;
int c[maxn];

void solve() {
  b.clear();
  for (int i = 0; i < n; i++) {
    b.push_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    int x = b.front();
    b.pop_front();
    int y = b.front();
    b.pop_front();
    ans0[i][0] = x;
    ans0[i][1] = y;
    if (x < y) {
      swap(x, y);
    }
    b.push_front(x);
    b.push_back(y);
  }
  int mx = b.front();
  b.pop_front();
  for (int i = 0; i < n - 1; i++) {
    c[i] = b.front();
    b.pop_front();
  }
  for (int qq = 0; qq < q; qq++) {
    long long k;
    scanf("%lld", &k);
    k--;
    if (k < n) {
      printf("%d %d\n", ans0[k][0], ans0[k][1]);
      continue;
    }
    k -= n;
    k %= (n - 1);
    printf("%d %d\n", mx, c[k]);
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