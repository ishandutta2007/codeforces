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

const int maxn = (1 << 16) + 5;
int n;
int deg[maxn], s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &deg[i], &s[i]);
  }
  return true;
}

vector<int> q;
vector<pair<int, int>> ans;

void solve() {
  q.clear();
  ans.clear();
  for (int v = 0; v < n; v++) {
    if (deg[v] == 1) {
      q.push_back(v);
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    if (deg[v] < 1) {
      continue;
    }
    int u = s[v];
    deg[v]--;
    deg[u]--;
    s[u] ^= v;
    ans.push_back(make_pair(v, u));
    if (deg[u] == 1) {
      q.push_back(u);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
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