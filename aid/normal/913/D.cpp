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

const int maxn = (int) 2e5 + 5;
int n, t;
int as[maxn], ts[maxn];

int read() {
  if (scanf("%d%d", &n, &t) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &as[i], &ts[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];

bool check(int k, bool out) {
  vector<int> ans;
  int curt = t;
  int need = k;
  for (int i = 0; i < n && need; i++) {
    int id = tosort[i].second;
    if (as[id] >= k && ts[id] <= curt) {
      curt -= ts[id];
      need--;
      ans.push_back(id);
    }
  }
  if (need) {
    return false;
  }
  if (out) {
    printf("%d\n%d\n", k, k);
    for (int i = 0; i < k; i++) {
      printf("%d ", ans[i] + 1);
    }
    printf("\n");
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(ts[i], i);
  }
  sort(tosort, tosort + n);
  int l = 0, r = n + 1;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m, false)) {
      l = m;
    } else {
      r = m;
    }
  }
  assert(check(l, true));
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