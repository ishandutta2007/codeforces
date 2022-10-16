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

const int maxn = (int) 2e5 + 5;
int n;
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  return true;
}

int bad[maxn];
vector<pair<int, int>> ans;

void swp(int i, int j) {
  swap(p[i], p[j]);
  bad[p[i]] ^= 1;
  bad[p[j]] ^= 1;
  ans.push_back(make_pair(i, j));
}

int used[maxn];
vector<int> c[2];

void fixCycle(int v, int len) {
  while (len > 2) {
    int u = p[v];
    if (bad[p[u]]) {
      v = u;
      continue;
    }
    swp(v, u);
    --len;
  }
  swp(v, p[v]);
}

void fixCycles() {
  swp(c[0][0], c[1][0]);
  int len = sz(c[0]) + sz(c[1]);
  int v = c[0][0];
  fixCycle(v, len);
  c[0].clear();
  c[1].clear();
}

void solve() {
  for (int i = 0; i < n; ++i) {
    bad[i] = 0;
    used[i] = false;
  }
  ans.clear();
  c[0].clear();
  c[1].clear();
  for (int s = 0; s < n; ++s) {
    if (p[s] == s || used[s]) {
      continue;
    }
    int id = 0;
    if (!c[id].empty()) {
      ++id;
    }
    for (int v = s; !used[v]; v = p[v]) {
      used[v] = true;
      c[id].push_back(v);
    }
    if (id == 0) {
      continue;
    }
    fixCycles();
  }
  if (!c[0].empty()) {
    for (int i = 0; i < n; ++i) {
      used[i] = false;
    }
    for (int i = 0; i < sz(c[0]); ++i) {
      used[c[0][i]] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        c[1] = {i};
        break;
      }
    }
    if (!c[1].empty()) {
      fixCycles();
    } else {
      int v = c[0][0], u = c[0][1], w = c[0][2];
      swp(v, u);
      swp(u, w);
      fixCycle(u, n);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
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