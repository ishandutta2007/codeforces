#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<int> G[N];

int MOD;
int dp[N][N], dps[N][N], c[N][N], z[N], pref[N], suff[N];

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int sub(int x, int y) {
  x -= y;
  return (x < 0 ? x+MOD : x);
}

void dfs(int v, int p) {
  if (v != 1) G[v].erase(find(G[v].begin(), G[v].end(), p));
  int m = G[v].size();
  for (int u: G[v]) {
    dfs(u, v);
  }

  for (int k = 1; k < N; k++) {
    dp[v][k] = 1;
    for (int u: G[v]) {
      dp[v][k] = 1LL*dp[v][k]*dps[u][k] % MOD;
    }
  }

  if (v != 1) {
    fill(z, z+m, 0);
    pref[0] = 1;
    suff[m] = 1;
    for (int k = 1; k < N; k++) {
      for (int i = 0; i < m; i++) {
        pref[i+1] = 1LL*pref[i]*dps[G[v][i]][k] % MOD;
        dp[v][k] = add(dp[v][k], 1LL*dp[G[v][i]][k]*z[i] % MOD);
      }
      for (int i = m-1; i >= 0; i--) {
        suff[i] = 1LL*suff[i+1]*dps[G[v][i]][k] % MOD;
      }
      for (int i = 0; i < m; i++) {
        z[i] = add(z[i], 1LL*pref[i]*suff[i+1] % MOD);
      }
    }
  }

  for (int i = 1; i < N; i++) {
    dps[v][i] = add(dps[v][i-1], dp[v][i]);
  }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> MOD;
  for (int i = 0; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = add(c[i-1][j-1], c[i-1][j]);
    }
  }

  for (int i = 0 ; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  
  for (int i = 2; i < N; i++) {
    for (int j = 0; j < i; j++) {
      dp[1][i] = sub(dp[1][i], 1LL*c[i][j]*dp[1][j] % MOD);
    }
  }

  for (int i = 1; i < n; i++) {
    cout << dp[1][i] << " \n"[i+1==n];
  }
}