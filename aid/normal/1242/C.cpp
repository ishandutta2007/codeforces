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

const int maxn = 15;
int n;
vector<int> as[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    as[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &as[i][j]);
    }
  }
  return true;
}

long long s[maxn];
vector<pair<long long, pair<int, int>>> tosort;
vector<int> used[maxn];
vector<pair<int, int>> path;

const int pown = (1 << maxn);
vector<pair<int, int>> cs[pown];
int dp[pown];

pair<int, int> ans[maxn];

void solve() {
  tosort.clear();
  long long need = 0;
  for (int i = 0; i < n; i++) {
    s[i] = 0;
    for (int j = 0; j < sz(as[i]); j++) {
      tosort.push_back(make_pair((long long) as[i][j], make_pair(i, j)));
      s[i] += as[i][j];
      need += as[i][j];
    }
    used[i] = vector<int>(sz(as[i]), 0);
  }
  if (need % n) {
    printf("No\n");
    return;
  }
  need /= n;
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < (1 << n); i++) {
    cs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(as[i]); j++) {
      if (used[i][j]) {
        continue;
      }
      path.clear();
      int x = i, y = j;
      bool bad = false;
      while (!used[x][y]) {
        used[x][y] = 1;
        path.push_back(make_pair(x, y));
        long long cur = need - (s[x] - as[x][y]);
        int pos = lower_bound(tosort.begin(), tosort.end(), make_pair(cur, make_pair(-1, -1))) - tosort.begin();
        if (pos >= sz(tosort) || tosort[pos].first != cur) {
          bad = true;
          break;
        }
        x = tosort[pos].second.first;
        y = tosort[pos].second.second;
      }
      if (!bad && used[x][y] == 1) {
        int pos = sz(path) - 1;
        while (path[pos] != make_pair(x, y)) {
          pos--;
        }
        int msk = 0;
        for (int ii = pos; ii < sz(path); ii++) {
          int x = path[ii].first;
          if (msk & (1 << x)) {
            bad = true;
            break;
          }
          msk |= (1 << x);
        }
        if (!bad) {
          cs[msk] = vector<pair<int, int>>(path.begin() + pos, path.end());
        }
      }
      for (int i = 0; i < sz(path); i++) {
        used[path[i].first][path[i].second] = 2;
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int msk = 0; msk < (1 << n); msk++) {
    if (dp[msk] == -1) {
      continue;
    }
    int nmsk = (((1 << n) - 1) ^ msk);
    for (int x = nmsk; x > 0; x = ((x - 1) & nmsk)) {
      if (cs[x].empty()) {
        continue;
      }
      dp[msk | x] = x;
    }
  }
  int msk = (1 << n) - 1;
  if (dp[msk] == -1) {
    printf("No\n");
    return;
  }
  printf("Yes\n");
  while (msk > 0) {
    int x = dp[msk];
    for (int i = 0; i < sz(cs[x]); i++) {
      int v = cs[x][i].first;
      ans[v] = make_pair(as[v][cs[x][i].second], cs[x][(i + sz(cs[x]) - 1) % sz(cs[x])].first);
    }
    msk ^= x;
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second + 1);
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