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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int c[2];
vector< pair<int, int> > a[2];

int read() {
  int n;
  if (scanf("%d%d%d", &n, &c[0], &c[1]) < 3) {
    return false;
  }
  a[0].clear();
  a[1].clear();
  for (int i = 0; i < n; i++) {
    int b, p;
    char ch;
    scanf("%d%d %c", &b, &p, &ch);
    int t = (ch == 'D');
    a[t].push_back(make_pair(p, b));
  }
  return true;
}

int pr[2][maxn];
int mx[2];

void solve() {
  sort(a[0].begin(), a[0].end());
  sort(a[1].begin(), a[1].end());
  int res = 0;
  for (int t = 0; t < 2; t++) {
    pr[t][0] = -inf;
    for (int i = 0; i < sz(a[t]); i++) {
      pr[t][i + 1] = max(pr[t][i], a[t][i].second);
    }
    for (int i = sz(a[t]) - 1, j = 0; i >= 0; i--) {
      while (j < i && a[t][j].first + a[t][i].first <= c[t]) {
        j++;
      }
      j = min(j, i);
      res = max(res, a[t][i].second + pr[t][j]);
    }
    mx[t] = -inf;
    for (int i = 0; i < sz(a[t]); i++) {
      if (a[t][i].first <= c[t]) {
        mx[t] = max(mx[t], a[t][i].second);
      }
    }
  }
  res = max(res, mx[0] + mx[1]);
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