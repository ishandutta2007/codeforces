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

const int maxn = (int) 5e4 + 5;
int n;
int x[maxn], y[maxn], z[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
  }
  return true;
}

vector<pair<int, int>> ans;
map<int, vector<int>> stx, sty;

vector<pair<int, int>> tosort;

int solve2(const vector<int> &v) {
  tosort.clear();
  for (int i = 0; i < sz(v); i++) {
    int id = v[i];
    tosort.push_back(make_pair(z[id], id));
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i + 1 < sz(tosort); i += 2) {
    ans.push_back(make_pair(tosort[i].second, tosort[i + 1].second));
  }
  if (sz(tosort) & 1) {
    return tosort.back().second;
  }
  return -1;
}

int solve1(const vector<int> &v) {
  sty.clear();
  for (int i = 0; i < sz(v); i++) {
    int id = v[i];
    sty[y[id]].push_back(id);
  }
  vector<int> ps;
  for (auto it = sty.begin(); it != sty.end(); it++) {
    const auto &u = it->second;
    int id = solve2(u);
    if (id != -1) {
      ps.push_back(id);
    }
  }
  for (int i = 0; i + 1 < sz(ps); i += 2) {
    ans.push_back(make_pair(ps[i], ps[i + 1]));
  }
  if (sz(ps) & 1) {
    return ps.back();
  }
  return -1;
}

void solve() {
  ans.clear();
  stx.clear();
  for (int i = 0; i < n; i++) {
    stx[x[i]].push_back(i);
  }
  vector<int> ps;
  for (auto it = stx.begin(); it != stx.end(); it++) {
    const auto &v = it->second;
    int id = solve1(v);
    if (id != -1) {
      ps.push_back(id);
    }
  }
  for (int i = 0; i < sz(ps); i += 2) {
    ans.push_back(make_pair(ps[i], ps[i + 1]));
  }
  for (int i = 0; i < sz(ans); i++) {
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