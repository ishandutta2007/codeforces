#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
const ll MOD = 1000000007;
ll ans = 0;
int n;

vector<vector<int>> sts;

vector<vector<ll>> prob(201);

ll inversemod(ll p, ll q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  ll k = q/p;
  ll b = inversemod(q-k*p, p);
  ll a = (1-b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

vector<int> findpath(int u, int v, int p) {
  if (u == v) return {u};
  for (int s: adj[v]) {
    if (s != p) {
      vector<int> path = findpath(u, s, v);
      if (path.size()) {
        path.push_back(v);
        return path;
      }
    }
  }
  return {};
}

int subtreesize(int v, int p) {
  int ans = 1;
  for (int u: adj[v]) {
    if (u != p) ans += subtreesize(u, v);
  }
  return ans;
}

void calc(int u, int v) {
  // generate path from u to v
  vector<int> path = findpath(u, v, v);
  int dist = path.size() - 1;
  ll val = subtreesize(u, path[1]);
  for (int i = 1; i < dist; i++) {
    int size = sts[path[i]][path[i-1]] - sts[path[i+1]][path[i]];
    assert(size > 0);
    val += prob[dist][i]*size % MOD;
    val %= MOD;
  }
  val *= inversemod(n, MOD);
  ans = (ans + 1 - val) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  adj.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  sts.resize(n);
  for (int u = 0; u < n; u++) {
    sts[u].resize(n);
    for (int v: adj[u]) {
      sts[u][v] = subtreesize(u, v);
    }
  }
  const int half = inversemod(2, MOD);
  prob[1] = {1, 0};
  for (int i = 2; i <= 200; i++) {
    prob[i].resize(i+1);
    prob[i][0] = 1;
    prob[i][i] = 0;
    for (int j = 1; j < i; j++) {
      prob[i][j] = half*(prob[i-1][j-1] + prob[i-1][j]) % MOD;
    }
  }

  for (int u = 0; u < n; u++) {
    for (int v = u+1; v < n; v++) {
      calc(u, v);
    }
  }
  ans = (ans + MOD) % MOD;
  assert(0 <= ans && ans < MOD);
  cout << ans << endl;
}