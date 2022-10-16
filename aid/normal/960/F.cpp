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

const int maxn = (int) 1e5 + 5;
int n, m;
int s[maxn], t[maxn], w[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &s[i], &t[i], &w[i]);
    s[i]--;
    t[i]--;
  }
  return true;
}

int dp[maxn];
set<pair<int, int>> st[maxn];

int get(int v, int w) {
  auto it = st[v].lower_bound(make_pair(w, -1));
  if (it == st[v].begin()) {
    return 0;
  }
  it--;
  return it->second;
}

void update(int v, int e) {
  auto it = st[v].lower_bound(make_pair(w[e] + 1, -1));
  if (it != st[v].begin()) {
    auto p = it;
    p--;
    if (p->second >= dp[e]) {
      return;
    }
    if (p->first == w[e]) {
      st[v].erase(p);
    }
  }
  while (it != st[v].end() && it->second <= dp[e]) {
    auto todel = it;
    it++;
    st[v].erase(todel);
  }
  st[v].insert(make_pair(w[e], dp[e]));
}

void solve() {
  for (int i = 0; i < n; i++) {
    st[i].clear();
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    dp[i] = get(s[i], w[i]) + 1;
    res = max(res, dp[i]);
    update(t[i], i);
  }
  printf("%d\n", res);
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