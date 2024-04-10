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

const int maxn = (int) 3e5 + 5;
int n;
int t[2][maxn];
long long sum[4][maxn];
int prv[2][maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &t[i][j]);
    }
  }
  return true;
}

int nxt[4][maxn];
int dp[maxn];
vector< pair<int, int> > go[2][maxn];

void add1(int a, int b, int val) {
  dp[max(a, b)] = max(dp[max(a, b)], val);
  if (a < b) {
    go[1][a].push_back(make_pair(b, val));
  } else if (b < a) {
    go[0][b].push_back(make_pair(a, val));
  }
}

void add(int a, int b, int val) {
  add1(a + 1, b, val);
  add1(a, b + 1, val);
  add1(a + 1, b + 1, val);
  if (nxt[1][a] < inf) {
    add1(nxt[1][a], b, val + 1);
  }
  if (nxt[2][b] < inf) {
    add1(a, nxt[2][b], val + 1);
  }
  if (a == b && nxt[3][a] < inf) {
    add1(nxt[3][a], nxt[3][a], val + 1);
  }
}

void solve() {
  for (int msk = 1; msk < 4; msk++) {
    sum[msk][0] = 0;
    for (int i = 0; i < n; i++) {
      auto &cur = sum[msk][i + 1];
      cur = sum[msk][i];
      for (int j = 0; j < 2; j++) {
        if (msk & (1 << j)) {
          cur += t[j][i];
        }
      }
    }
    map<long long, int> lst;
    for (int i = n; i >= 0; i--) {
      if (!lst.count(sum[msk][i])) {
        nxt[msk][i] = inf;
      } else {
        nxt[msk][i] = lst[sum[msk][i]];
      }
      lst[sum[msk][i]] = i;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      go[i][j].clear();
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    add(i, i, dp[i]);
    int to[2] = {inf, inf};
    for (int it = 0; it < 2; it++) {
      for (int j = 0; j < sz(go[it][i]); j++) {
        if (go[it][i][j].second > dp[i] && go[it][i][j].first < to[it]) {
          to[it] = go[it][i][j].first;
        }
      }
    }
    if (to[0] < inf) {
      add(to[0], i, dp[i] + 1);
    }
    if (to[1] < inf) {
      add(i, to[1], dp[i] + 1);
    }
  }
  printf("%d\n", dp[n]);
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