#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int inf = 1000000000;

struct To {
  int node, k, t;
};

vector<int>G[MAXN];
int dp[MAXN][MAXN][5];
vector<To>fr[MAXN][MAXN][5];

void Clear(int n) {
  for (int i = 0; i <= n; ++i)
    G[i].clear();
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      dp[i][j][0] = dp[i][j][1] = 0;
      fr[i][j][0].clear();
      fr[i][j][1].clear();
    }
}

int dfs(int node) {
  int sz = 1;
  dp[node][1][0] = 0;
  dp[node][1][1] = 0;
  for (auto it:G[node]) {
    int k = dfs(it);
    for (int i = sz; i >= 0; --i)
      for (int j = k; j >= 0; --j) {
        if (dp[node][i + j][1] > dp[node][i][1] + 1 + dp[it][j][1] + 1) {
          dp[node][i + j][1] = dp[node][i][1] + 1 + dp[it][j][1] + 1;
          fr[node][i + j][1].clear();
          for (auto it:fr[node][i][1])
            fr[node][i + j][1].push_back(it);
          fr[node][i + j][1].push_back({it, j, 1});
        }
        if (dp[node][i + j][0] > dp[node][i][1] + 1 + dp[it][j][0]) {
          dp[node][i + j][0] = dp[node][i][1] + 1 + dp[it][j][0];
          fr[node][i + j][0].clear();
          for (auto it:fr[node][i][1])
            fr[node][i + j][0].push_back(it);
          fr[node][i + j][0].push_back({it, j, 0});
        }
        if (dp[node][i + j][0] > dp[node][i][0] + 1 + dp[it][j][1] + 1) {
          dp[node][i + j][0] = dp[node][i][0] + 1 + dp[it][j][1] + 1;
          fr[node][i + j][0].clear();
          for (auto it:fr[node][i][0])
            fr[node][i + j][0].push_back(it);
          fr[node][i + j][0].push_back({it, j, 1});
        }
      }
    sz += k;
  }

  return sz;
}

vector<int>getSol(int node, int k, int t) {
  To go = {-1, -1, -1};
  vector<int>sol;
  sol.push_back(node);

  for (auto it:fr[node][k][t]) {
    if (it.t == 0) {
      go = it;
    } else {
      vector<int>aux = getSol(it.node, it.k, it.t);
      for (auto it:aux)
        sol.push_back(it);
      sol.push_back(node);
    }
  }
  if (go.node != -1) {
    vector<int>aux = getSol(go.node, go.k, go.t);
    for (auto it:aux)
      sol.push_back(it);
  }
  return sol;
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    G[p].push_back(i);
  }

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j][0] = dp[i][j][1] = inf;

  dfs(1);

  vector<int>sol = getSol(1, k, 0);
  printf("%d\n", (int)sol.size() - 1);
  for (auto it:sol)
    printf("%d ", it);
  printf("\n");

  Clear(n);
}

int main() {
  //freopen("date.in", "r", stdin);
  //freopen("date.out", "w", stdout);

  int t;
  scanf("%d", &t);
  while (t--)
    solve();

  return 0;
}