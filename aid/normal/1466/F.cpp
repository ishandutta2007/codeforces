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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

const int maxn = (int) 5e5 + 5;
int n, m;
int es[maxn][2];

bool read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  ++n;
  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < 2; ++j) {
      es[i][j] = -1;
    }
    for (int j = 0; j < k; ++j) {
      int v;
      scanf("%d", &v);
      --v;
      es[i][j] = v;
    }
  }
  return true;
}

int p[maxn], ts[maxn];
vector<int> ans;

int get(int x) {
  return (p[x] == x? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  return true;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    ts[i] = 1;
  }
  int res = 1;
  ans.clear();
  for (int i = 0; i < m; ++i) {
    int v = es[i][0], u = es[i][1];
    if (v == -1) {
      continue;
    }
    if (u == -1) {
      u = n - 1;
    }
    if (unite(v, u)) {
      res = mul(res, 2);
      ans.push_back(i);
    }
  }
  printf("%d %d\n", res, sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
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