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

const int maxn = 5005;
int n;
int a[maxn], b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(a[i], b[i]);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    a[i] = tosort[i].first;
    b[i] = tosort[i].second;
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= cur) {
      cur = b[i];
    } else {
      cur = a[i];
    }
  }
  printf("%d\n", cur);
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