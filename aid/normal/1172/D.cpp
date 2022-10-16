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

const int maxn = 1005;
int n;
int r[maxn], c[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &r[i]);
    r[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
  }
  return true;
}

int p[maxn], q[maxn];
vector<vector<int>> ans;

void solve() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    q[i] = i;
  }
  ans.clear();
  for (int i = 0; i < n; i++) {
    int x = i;
    while (r[p[x]] != i) {
      x++;
    }
    int y = i;
    while (c[q[y]] != i) {
      y++;
    }
    if (x == i) {
      if (y == i) {
      } else {
        ans.push_back({i, i, i, y});
        swap(q[i], q[y]);
      }
    } else {
      if (y == i) {
        ans.push_back({i, i, x, i});
        swap(p[i], p[x]);
      } else {
        ans.push_back({i, y, x, i});
        swap(p[i], p[x]);
        swap(q[i], q[y]);
      }
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
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