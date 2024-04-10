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

const int maxn = (int) 3e5 + 5;
int n;
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int q[maxn];
vector<pair<int, int>> ans;

void op(int i, int j) {
  ans.push_back(make_pair(i, j));
  int x = p[i], y = p[j];
  swap(p[i], p[j]);
  swap(q[x], q[y]);
}

void solve() {
  for (int i = 0; i < n; i++) {
    q[p[i]] = i;
  }
  ans.clear();
  for (int i = 1; i < n - 1; i++) {
    int j = q[i];
    if (j >= n / 2) {
      op(j, 0);
      j = 0;
    } else {
      op(j, n - 1);
      j = n - 1;
    }
    if (i >= n / 2 && j == n - 1) {
      op(j, 0);
      j = 0;
    } else if (i < n / 2 && j == 0) {
      op(j, n - 1);
      j = n - 1;
    }
    op(j, i);
  }
  if (p[0] != 0) {
    op(0, n - 1);
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
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