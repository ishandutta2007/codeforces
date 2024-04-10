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

const int maxn = (int) 1e5 + 5;
int n, s0, s1;
int a[maxn];

int read() {
  if (scanf("%d%d%d", &n, &s0, &s1) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

set<int> st;

bool check(int d) {
  if (abs(s1 - s0) > d) {
    return false;
  }
  st.clear();
  for (int it = 0; it < 2; it++) {
    if (abs(a[0] - s0) <= d) {
      st.insert(s0);
    }
    swap(s0, s1);
  }
  for (int i = 0; i + 1 < n; i++) {
    if (st.empty()) {
      return false;
    }
    int x = a[i + 1];
    while (!st.empty()) {
      auto it = st.begin();
      if (abs(x - *it) <= d) {
        break;
      }
      st.erase(it);
    }
    while (!st.empty()) {
      auto it = st.end();
      it--;
      if (abs(x - *it) <= d) {
        break;
      }
      st.erase(it);
    }
    if (abs(x - a[i]) <= d) {
      st.insert(a[i]);
    }
  }
  return !st.empty();
}

void solve() {
  int l = 0, r = inf;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%d\n", r);
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