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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector< pair<int, int> > evs;

void solve() {
  evs.clear();
  for (int i = 0; i + 2 <= n; i++) {
    int d = min(i, n - (i + 2));
    int x = n - 2 * d - 2;
    int val = max(a[i], a[i + 1]);
    evs.push_back(make_pair(x, val));
  }
  for (int i = 0; i + 3 <= n; i++) {
    int d = min(i, n - (i + 3));
    int x = n - 2 * d - 3;
    int val = max(min(a[i], a[i + 1]), min(a[i + 1], a[i + 2]));
    evs.push_back(make_pair(x, val));
  }
  sort(evs.begin(), evs.end());
  int res[2] = {-inf, -inf};
  for (int k = 0, pos = 0; k < n - 1; k++) {
    int t = (k & 1);
    while (pos < sz(evs) && evs[pos].first <= k) {
      res[t] = max(res[t], evs[pos].second);
      pos++;
    }
    printf("%d ", res[t]);
  }
  int mx = -inf;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
  }
  printf("%d\n", mx);
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