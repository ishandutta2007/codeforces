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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<vector<int>> ans;

const int pown = (1 << 20);
int dp[pown];
int msk[pown];

bool solve1() {
  vector<vector<int>> ops;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int k = j + (j - i);
      if (k >= n) {
        break;
      }
      ops.push_back({i, j, k});
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    dp[i] = inf;
  }
  for (int i = 0; i < (1 << sz(ops)); i++) {
    int x = 0;
    int cnt = 0;
    for (int j = 0; j < sz(ops); j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < sz(ops[j]); k++) {
          x ^= (1 << ops[j][k]);
        }
        cnt++;
      }
    }
    if (cnt < dp[x]) {
      dp[x] = cnt;
      msk[x] = i;
    }
  }
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      x ^= (1 << i);
    }
  }
  if (dp[x] >= inf) {
    return false;
  }
  for (int i = 0; i < sz(ops); i++) {
    if (msk[x] & (1 << i)) {
      ans.push_back(ops[i]);
    }
  }
  return true;
}

void reduce(int K, int M, int minn) {
  vector<vector<int>> ops;
  vector<int> msks;
  int U = 3014655;
  if (K != 6) {
    U = -1;
  }
  int cur = 0;
  for (int i = 0; i < K; i++) {
    for (int j = i + 1; j < M; j++) {
      int k = j + (j - i);
      if (k >= M) {
        break;
      }
      if (U & (1 << cur)) {
        ops.push_back({i, j, k});
        int x = 0;
        if (i < K) {
          x ^= (1 << i);
        }
        if (j < K) {
          x ^= (1 << j);
        }
        if (k < K) {
          x ^= (1 << k);
        }
        msks.push_back(x);
      }
      cur++;
    }
  }
  //eprintf("%d\n", sz(ops));
  for (int i = 0; i < (1 << K); i++) {
    dp[i] = inf;
  }
  for (int i = 0; i < (1 << sz(ops)); i++) {
    int x = 0;
    int cnt = 0;
    for (int j = 0; j < sz(ops); j++) {
      if (i & (1 << j)) {
        x ^= msks[j];
        cnt++;
      }
    }
    if (cnt < dp[x]) {
      dp[x] = cnt;
      msk[x] = i;
    }
  }
  /*int val = 0;
  int used = 0;
  for (int i = 0; i < (1 << K); i++) {
    val = max(val, dp[i]);
    used |= msk[i];
  }
  eprintf("%d\n", val);
  eprintf("%d\n", used);*/
  while (n >= minn) {
    int x = 0;
    for (int i = 0; i < K; i++) {
      if (a[n - 1 - i]) {
        x ^= (1 << i);
      }
    }
    assert(dp[x] <= 2);
    for (int i = 0; i < sz(ops); i++) {
      if (msk[x] & (1 << i)) {
        vector<int> cur;
        for (int j = 0; j < sz(ops[i]); j++) {
          cur.push_back(n - 1 - ops[i][j]);
          a[n - 1 - ops[i][j]] ^= 1;
        }
        ans.push_back(cur);
      }
    }
    n -= K;
  }
}

void solve() {
  ans.clear();
  reduce(6, 12, 14);
  reduce(3, 9, 11);
  if (!solve1()) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    sort(ans[i].begin(), ans[i].end());
    for (int j = 0; j < sz(ans[i]); j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
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