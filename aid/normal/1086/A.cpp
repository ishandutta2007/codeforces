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

int xa, ya, xb, yb, xc, yc;

bool read() {
  if (scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc) < 6) {
    return false;
  }
  return true;
}

void solve() {
  if (xa > xb) {
    swap(xa, xb);
    swap(ya, yb);
  }
  if (xa > xc) {
    swap(xa, xc);
    swap(ya, yc);
  }
  if (xb > xc) {
    swap(xb, xc);
    swap(yb, yc);
  }
  vector<pair<int, int>> ans;
  for (int i = xa; i < xb; i++) {
    ans.push_back(make_pair(i, ya));
  }
  int dy = (ya < yb ? 1 : -1);
  for (int i = ya; i != yb; i += dy) {
    ans.push_back(make_pair(xb, i));
  }
  ans.push_back(make_pair(xb, yb));
  if (yc > max(ya, yb)) {
    for (int i = max(ya, yb) + 1; i <= yc; i++) {
      ans.push_back(make_pair(xb, i));
    }
  } else if (yc < min(ya, yb)) {
    for (int i = min(ya, yb) - 1; i >= yc; i--) {
      ans.push_back(make_pair(xb, i));
    }
  }
  for (int i = xb + 1; i <= xc; i++) {
    ans.push_back(make_pair(i, yc));
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