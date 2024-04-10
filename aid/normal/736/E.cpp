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

const int maxn = 3005;
int n, m;
int ds[maxn];

bool read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ds[i]);
  }
  return true;
}

char ans[maxn][maxn];
int used[maxn];

void solve() {
  int s = 0;
  for (int i = 0; i < n; i++) {
    ds[i] -= m - 1;
    s += ds[i];
    if (s > (m - i - 1) * (i + 1)) {
      printf("no\n");
      return;
    }
  }
  for (int i = n; i < m; i++) {
    ds[i] = min(ds[i - 1], (m - i - 1) * (i + 1) - s);
    s += ds[i];
  }
  if (s != 0) {
    printf("no\n");
    return;
  }
  printf("yes\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = (i == j ? 'X' : 'D');
    }
    ans[i][m] = 0;
    used[i] = false;
  }
  for (int it = 0; it < m; it++) {
    vector<pair<int, int>> tosort;
    for (int i = 0; i < m; i++) {
      if (!used[i]) {
        tosort.push_back(make_pair(ds[i], i));
      }
    }
    sort(tosort.begin(), tosort.end());
    int v = tosort.back().second;
    tosort.pop_back();
    used[v] = true;
    for (int i = 0; i < ds[v]; i++) {
      int u = tosort[i].second;
      ans[v][u] = 'W';
      ans[u][v] = 'L';
      ds[u]++;
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%s\n", ans[i]);
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