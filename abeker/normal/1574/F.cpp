#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int N, M, K, L;
vector <pii> adj[MAXN];
int pos[MAXN];
int cnt[MAXN];
int dp[MAXN];

void load() {
  scanf("%d%d%d", &N, &M, &K);
  while (N--) {
    int c;
    scanf("%d", &c);
    int prev = 0;
    while (c--) {
      int x;
      scanf("%d", &x);
      if (prev) {
        adj[prev].push_back({x, 1});
        adj[x].push_back({prev, -1});
      }
      prev = x;
    }
  }
}

int dfs(int x, int p, set <int> &used) {
  if (pos[x] != INF)
    return pos[x] == p ? 0 : -1;
  pos[x] = p;
  int res = 1;
  bool bad = used.count(p);
  used.insert(p);
  for (auto it : adj[x]) {
    int tmp = dfs(it.first, p + it.second, used);
    if (tmp == -1)
      bad = true;
    else 
      res += tmp;
  }
  return bad ? -1 : res;
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int solve() {
  memset(pos, INF, sizeof pos);
  for (int i = 1; i <= K; i++)
    if (pos[i] == INF) {
      set <int> curr;
      int tmp = dfs(i, 0, curr);
      if (tmp != -1)
        cnt[tmp]++;
    }
  vector <pii> trans;
  for (int i = 1; i <= K; i++)
    if (cnt[i])
      trans.push_back({i, cnt[i]});
  dp[0] = 1;
  for (int i = 1; i <= M; i++)
    for (auto it : trans)
      if (it.first <= i)
        dp[i] = add(dp[i], mul(it.second, dp[i - it.first]));
  return dp[M];
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}