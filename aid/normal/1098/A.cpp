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

const int maxn = (int) 1e5 + 5;
int n;
int s[maxn];
int ps[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  ps[0] = -1;
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
    ps[i] = p;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  return true;
}

void solve() {
  for (int v = n - 1; v >= 0; v--) {
    if (s[v] != -1) {
      continue;
    }
    int val = inf;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      val = min(val, s[u]);
    }
    if (val >= inf) {
      val = s[ps[v]];
    }
    if (val < s[ps[v]]) {
      printf("-1\n");
      return;
    }
    s[v] = val;
  }
  long long res = 0;
  for (int v = 0; v < n; v++) {
    res += s[v] - (ps[v] == -1 ? 0 : s[ps[v]]);
  }
  printf("%lld\n", res);
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