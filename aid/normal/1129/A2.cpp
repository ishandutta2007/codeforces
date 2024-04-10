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

const int maxn = 5005;
int n, m;
vector<int> bs[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    bs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    bs[a].push_back(b);
  }
  return true;
}

int d[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    auto &cur = d[i];
    cur = inf;
    for (int j = 0; j < sz(bs[i]); j++) {
      int b = bs[i][j];
      int x = (b < i ? n - i + b : b - i);
      cur = min(cur, x);
    }
  }
  for (int s = 0; s < n; s++) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (bs[i].empty()) {
        continue;
      }
      int cur = (i < s ? n - s + i : i - s) + (sz(bs[i]) - 1) * n + d[i];
      res = max(res, cur);
    }
    printf("%d ", res);
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