#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

enum type { UP, DOWN };

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int N;
vector <pii> adj[MAXN], ch[MAXN];
int dp_dir[MAXN][2], dp_undir[MAXN][2];
int last[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back({i, v});
    adj[v].push_back({i, u});
  }
}

void dfs(int x, int p, int id) {
  for (auto it : adj[x])
    if (it.second != p) {
      dfs(it.second, x, it.first);
      ch[x].push_back(it);
    }
  sort(ch[x].begin(), ch[x].end());
  for (auto it : ch[x])
    if (it.first < id)
      last[x] = it.first;
}

int dir(int, type);
int undir(int, bool);

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int dir(int x, type edge) {
  int &ref = dp_dir[x][edge];
  if (ref != -1)
    return ref;
  int dp[2] = {1, 0};
  for (auto it : ch[x]) {
    bool points = edge && (it.first > last[x]);
    dp[1] = add(mul(dp[0], it.first <= last[x] || points ? 0 : dir(it.second, UP)), mul(dp[1], undir(it.second, true)));
    dp[0] = mul(dp[0], add(points ? 0 : dir(it.second, DOWN), undir(it.second, points)));
  }
  return ref = add(dp[0], dp[1]);
}

int undir(int x, bool sat) {
  int &ref = dp_undir[x][sat];
  if (ref != -1)
    return ref;
  int dp[2] = {sat || last[x], 0};
  for (auto it : ch[x]) {
    dp[1] = add(mul(dp[0], dir(it.second, UP)), mul(dp[1], undir(it.second, true)));
    dp[0] = sat || it.first < last[x] ? mul(dp[0], add(dir(it.second, DOWN), undir(it.second, false))) : 0;
  }
  return ref = add(dp[1], dp[0]);
}

int solve() {
  memset(dp_dir, -1, sizeof dp_dir);
  memset(dp_undir, -1, sizeof dp_undir);
  dfs(1, 0, 0);
  return undir(1, true);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}