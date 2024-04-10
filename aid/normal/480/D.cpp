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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

#define ws wwwwwwwwwwws

const int maxn = 505, maxs = 1005;
int n;
int ls[maxn], rs[maxn], ws[maxn], ss[maxn], vs[maxn];

int read() {
  int s;
  if (scanf("%d%d", &n, &s) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%d", &ls[i], &rs[i], &ws[i], &ss[i], &vs[i]);
  }
  ls[n] = 0;
  rs[n] = 2 * n - 1;
  ws[n] = 0;
  ss[n] = s;
  vs[n] = 0;
  n++;
  return true;
}

vector<int> ids[2 * maxn];
pair<int, int> tosort[maxn];

int dp[maxn][maxs];
int d[2 * maxn];

void solve() {
  for (int i = 0; i < 2 * n; i++) {
    ids[i].clear();
  }
  for (int i = 0; i < n; i++) {
    ids[ls[i]].push_back(i);
    tosort[i] = make_pair(rs[i] - ls[i], i);
  }
  sort(tosort, tosort + n);
  for (int it = 0; it < n; it++) {
    int i = tosort[it].second;
    for (int v = 0; v < maxs; v++) {
      auto &cur = dp[i][v];
      memset(d, -1, sizeof(d));
      d[ls[i]] = 0;
      for (int x = ls[i]; x < rs[i]; x++) {
        auto c = d[x];
        if (c < 0) {
          continue;
        }
        {
          auto &nxt = d[x + 1];
          nxt = max(nxt, c);
        }
        for (int j = 0; j < sz(ids[x]); j++) {
          int id = ids[x][j];
          if (id != i && rs[id] <= rs[i] && ws[id] <= v) {
            int nv = min(v - ws[id], ss[id]);
            auto &nxt = d[rs[id]];
            nxt = max(nxt, c + dp[id][nv]);
          }
        }
      }
      cur = vs[i] + d[rs[i]];
    }
  }
  printf("%d\n", dp[n - 1][ss[n - 1]]);
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