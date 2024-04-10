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

const int maxn = 2005;
int n, m;
int ps[maxn][2], qs[maxn][2];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &ps[i][j]);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &qs[i][j]);
    }
  }
  return true;
}

vector<pair<int, int>> evs;

void solve() {
  evs.clear();
  int up = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (qs[j][0] < ps[i][0] || qs[j][1] < ps[i][1]) {
        continue;
      }
      evs.push_back(make_pair(qs[j][0] - ps[i][0], qs[j][1] - ps[i][1] + 1));
    }
  }
  sort(evs.begin(), evs.end(), greater<pair<int, int>>());
  int res = up + (evs.empty() ? 0 : evs[0].first + 1);
  for (int j = 0; j < sz(evs);) {
    int i = j;
    while (j < sz(evs) && evs[j].first == evs[i].first) {
      up = max(up, evs[j].second);
      ++j;
    }
    res = min(res, up + (j < sz(evs) ? evs[j].first + 1 : 0));
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