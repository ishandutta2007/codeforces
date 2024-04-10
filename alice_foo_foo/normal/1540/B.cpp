#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1ull * x * y % mod; }
inline int qsm(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    y >>= 1; x = mul(x, x);
  }
  return ans;
}

const int maxN = 234;

vector<int> adj[maxN];
int dp[maxN][maxN];
int n, ans;

int dep[maxN], fa[maxN], siz[maxN], rt, son;
void dfs(int u) {
  siz[u] = 1;
  for (unsigned i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != fa[u]) {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
      siz[u] += siz[v];
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i <= n; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
      dp[i][j] = mul(dp[i][j], (mod + 1) / 2);
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(fa, 0, sizeof(fa));
    dep[i] = 0;
    dfs(i);
    for (int j = 1; j < i; j++) {
      int tmp = j;
      while (fa[tmp] != i) {
        int las = tmp;
        tmp = fa[tmp];
        ans = add(ans, mul(siz[tmp] - siz[las], dp[dep[tmp]][dep[j] - dep[tmp]]));
      }
      ans = add(ans, sub(n, siz[tmp]));
    }
  }
  printf("%d\n", mul(ans, qsm(n, mod - 2)));
  return 0;
}