#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int maxn = 3005;
int n;
vector<int> children[maxn];
int inv[maxn];
int binom[maxn][maxn];
vector<int> dp[maxn];

void dfs(int v) {
  vector<int> a(n, 1);
  for (int u: children[v]) {
    dfs(u);
    for (int i = 0; i <= n-1; i++) {
      a[i] = 1LL * a[i] * dp[u][i+1] % MOD;
    }
  }
  dp[v].resize(n+1);
  dp[v][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[v][i+1] = (dp[v][i] + a[i]) % MOD;
  }
}

int basic_binom(int n, int k) {
  if (k > n || k < 0) return 0;
  int ans = 1;
  for (int i = 1; i <= k; i++) {
    ans = 1LL * ans * (n-i+1) % MOD;
    ans = 1LL * ans * inv[i] % MOD;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
  binom[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      binom[i][j] = binom[i-1][j] % MOD;
      if (j) binom[i][j] = (binom[i][j] + binom[i-1][j-1]) % MOD;
    }
  }

  int D;
  cin >> n >> D;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    children[p].push_back(i);
  }
  dfs(1);
  /*
  for (int i = 1; i <= n; i++) {
    cout << i << endl;
    for (int u: dp[i]) cout << u << ' ';
    cout << endl;
  }
  */
  int ans = 0;
  vector<int> colorcounts(n+1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      int sign = ((i-j)&1 ? -1 : 1);
      colorcounts[i] += 1LL * sign * binom[i][j] * dp[1][j] % MOD;
      colorcounts[i] %= MOD;
    }
    ans += 1LL * colorcounts[i] * basic_binom(D, i) % MOD;
    ans %= MOD;
  }
  cout << (ans+MOD)%MOD << endl;
}