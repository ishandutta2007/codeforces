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
int d[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
vector<int> vs[2 * maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(d[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < 2 * n; i++) {
    vs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int id = tosort[i].second;
    vs[n + i].push_back(2 * id);
    vs[n + i - d[id]].push_back(2 * id + 1);
  }
  for (int i = 0; i + 1 < 2 * n; i++) {
    for (int j = 0; j < sz(vs[i]); j++) {
      printf("%d %d\n", vs[i][j] + 1, vs[i + 1][0] + 1);
    }
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