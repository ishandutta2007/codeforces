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
int p[maxn], c[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i], &c[i]);
    p[i]--;
  }
  return true;
}

vector<pair<int, int>> qs[maxn];
pair<int, int> tosort[maxn];
int used[maxn];

void solve() {
  for (int i = 0; i < m; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < n; i++) {
    qs[p[i]].push_back(make_pair(c[i], i));
  }
  for (int i = 0; i < m; i++) {
    sort(qs[i].begin(), qs[i].end());
  }
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(c[i], i);
  }
  sort(tosort, tosort + n);
  long long res = infll;
  for (int x = 0; x < n; x++) {
    int cnt = sz(qs[0]);
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    long long cur = 0;
    for (int i = 1; i < m; i++) {
      int k = sz(qs[i]) - x;
      if (k <= 0) {
        continue;
      }
      for (int j = 0; j < k; j++) {
        int id = qs[i][j].second;
        cur += c[id];
        used[id] = true;
        cnt++;
      }
    }
    for (int i = 0; i < n && cnt <= x; i++) {
      int id = tosort[i].second;
      if (used[id] || p[id] == 0) {
        continue;
      }
      cur += c[id];
      used[id] = true;
      cnt++;
    }
    res = min(res, cur);
  }
  printf("%lld\n", res);
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