#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5, maxt = (int) 1e6 + 5;
int n, m, ts;
int col[maxn], tcol[maxt];
pair<int, int> e[maxn];
vector<int> t[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &e[i].first, &e[i].second);
    e[i].first--;
    e[i].second--;
  }
  ts = 0;
  for (int i = 0; i < n; i++) {
    t[i].clear();
    int k;
    scanf("%d", &k);
    t[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &t[i][j]);
      t[i][j]--;
      ts = max(ts, t[i][j] + 1);
    }
  }
  return true;
}

void solve() {
  while (true) {
    for (int i = 0; i < n; i++) {
      col[i] = t[i][rnd(sz(t[i]))];
    }
    for (int i = 0; i < ts; i++) {
      tcol[i] = rnd(2);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      if (tcol[col[e[i].first]] != tcol[col[e[i].second]]) {
        cnt++;
      }
    }
    if (2 * cnt >= m) {
      for (int i = 0; i < n; i++) {
        printf("%d ", col[i] + 1);
      }
      printf("\n");
      for (int i = 0; i < ts; i++) {
        printf("%d ", tcol[i] + 1);
      }
      printf("\n");
      return;
    }
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}