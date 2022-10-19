#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+5;
int fact[N];
int invfact[N];
vector<int> G[N];
int sz[N], dp[N];
int k, val;
int vals[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

void dfs(int v, int p) {
  sz[v] = 1;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    sz[v] += sz[u];
    dp[v] = (dp[v]-binommod(sz[u], k))%MOD;
  }
  dp[v] = (dp[v] + binommod(sz[v], k)) % MOD;
  val = (val + 1LL*dp[v]*sz[v]) % MOD;
}

void reroot(int rt, int nrt) {
  int old_sz_rt = sz[rt];
  int old_sz_nrt = sz[nrt];
  int old_dp_rt = dp[rt];
  int old_dp_nrt = dp[nrt];
  sz[rt] = old_sz_rt-old_sz_nrt;
  sz[nrt] = old_sz_rt;
  dp[rt] = (0LL+old_dp_rt-binommod(old_sz_rt, k)+binommod(old_sz_nrt, k)+binommod(sz[rt], k)) % MOD;

  dp[nrt] = (0LL+old_dp_nrt-binommod(old_sz_nrt, k)-binommod(sz[rt], k)+binommod(sz[nrt], k))%MOD;
  val = (val + 1LL*dp[rt]*sz[rt] + 1LL*dp[nrt]*sz[nrt] - 1LL*old_sz_rt*old_dp_rt - 1LL*old_sz_nrt*old_dp_nrt)%MOD;
}

void dfs2(int v, int p) {
  vals[v] = val;
  for (int u: G[v]) {
    if (u == p) continue;
    reroot(v, u);
    dfs2(u, v);
    reroot(u, v);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  dfs2(1, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans+vals[i])%MOD;
  }
  cout << (ans+MOD)%MOD << '\n';
}