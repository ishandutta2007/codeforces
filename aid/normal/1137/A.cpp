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
int n, m;
int a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

int b[maxn];
int ls[maxn], rs[maxn];

void get(int n) {
  vector<int> bs;
  for (int i = 0; i < n; i++) {
    bs.push_back(b[i]);
  }
  sort(bs.begin(), bs.end());
  bs.erase(unique(bs.begin(), bs.end()), bs.end());
  for (int i = 0; i < n; i++) {
    int x = lower_bound(bs.begin(), bs.end(), b[i]) - bs.begin();
    ls[i] = x;
    rs[i] = sz(bs) - x - 1;
  }
}

int allls[maxn][maxn], allrs[maxn][maxn];
int ans[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j] = a[i][j];
    }
    get(m);
    for (int j = 0; j < m; j++) {
      allls[i][j] = ls[j];
      allrs[i][j] = rs[j];
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      b[i] = a[i][j];
    }
    get(n);
    for (int i = 0; i < n; i++) {
      int l = max(ls[i], allls[i][j]), r = max(rs[i], allrs[i][j]);
      ans[i][j] = l + 1 + r;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", ans[i][j]);
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