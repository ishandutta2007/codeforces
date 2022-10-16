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

const int maxn = 105;
int n, m;
int a[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j][i]);
    }
  }
  return true;
}

pair<int, int> b[maxn];
vector<int> ans;

void solve() {
  ans.clear();
  for (int i = 0; i < m; i++) {
    ans.push_back(i);
  }
  for (int s = 0; s < n - 1; s++) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
      int cur = a[s][i] - a[n - 1][i];
      sum += cur;
      b[i] = make_pair(cur, i);
    }
    sort(b, b + m);
    vector<int> cur;
    for (int i = 0; sum < 0; i++) {
      sum -= b[i].first;
      cur.push_back(b[i].second);
    }
    if (sz(cur) < sz(ans)) {
      ans = cur;
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i] + 1);
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