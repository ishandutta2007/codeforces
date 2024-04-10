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

const int maxn = (int) 3e5 + 5;
int n;
vector<pair<pair<int, int>, int>> p[2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  p[0].clear();
  p[1].clear();
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) {
      p[0].push_back(make_pair(make_pair(a, b), i));
    } else {
      p[1].push_back(make_pair(make_pair(a, b), i));
    }
  }
  return true;
}

void solve() {
  int t;
  if (sz(p[0]) > sz(p[1])) {
    sort(p[0].begin(), p[0].end());
    reverse(p[0].begin(), p[0].end());
    t = 0;
  } else {
    sort(p[1].begin(), p[1].end());
    t = 1;
  }
  printf("%d\n", sz(p[t]));
  for (int i = 0; i < sz(p[t]); i++) {
    printf("%d ", p[t][i].second + 1);
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