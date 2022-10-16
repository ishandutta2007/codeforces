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

const int logn = 21, maxn = (1 << logn) + 5;
int h, g;
int n, m;
int a[maxn];

bool read() {
  if (scanf("%d%d", &h, &g) < 2) {
    return false;
  }
  n = (1 << h) - 1;
  m = (1 << g) - 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

long long res;
vector<int> ans;

bool del(int v) {
  if (!a[v]) {
    return false;
  }
  int u = v;
  while (true) {
    int l = 2 * u, r = 2 * u + 1;
    if (!a[l] && !a[r]) {
      break;
    }
    if (a[l] > a[r]) {
      u = l;
    } else {
      u = r;
    }
  }
  if (u <= m) {
    return false;
  }
  res -= a[v];
  ans.push_back(v);
  u = v;
  while (true) {
    int l = 2 * u, r = 2 * u + 1;
    if (!a[l] && !a[r]) {
      a[u] = 0;
      break;
    }
    if (a[l] > a[r]) {
      a[u] = a[l];
      u = l;
    } else {
      a[u] = a[r];
      u = r;
    }
  }
  return true;
}

void dfs(int v) {
  while (del(v)) ;
  if (a[v]) {
    dfs(2 * v);
    dfs(2 * v + 1);
  }
}

void solve() {
  for (int i = n + 1; i <= 2 * n + 1; i++) {
    a[i] = 0;
  }
  res = 0;
  for (int i = 1; i <= n; i++) {
    res += a[i];
  }
  ans.clear();
  dfs(1);
  printf("%lld\n", res);
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}