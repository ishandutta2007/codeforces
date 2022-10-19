#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;
vector<vector<int>> adj;

ll prodsum(vector<int>& arr, int k) {
  vector<ll> sym(k+1, 0);
  sym[0] = 1;
  for (int a: arr) {
    for (int i = k-1; i >= 0; i--) {
      sym[i+1] += a*sym[i];
      sym[i+1] %= MOD;
    }
  }
  return sym[k];
}

int depthcount(int v, int p, int d) {
  if (d == 0) return 1;
  int ans = 0;
  for (int u: adj[v]) {
    if (u != p) ans += depthcount(u, v, d-1);
  }
  return ans;
}

void solve () {
  int n, k;
  cin >> n >> k;
  adj.resize(n);
  adj.clear();
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (k == 2) {
    cout << (n*n-n)/2 << endl;
    return;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int d = 1; d < n; d++) {
      vector<int> terms;
      for (int u: adj[i]) {
        int p = depthcount(u, i, d-1);
        if (p != 0) terms.push_back(p);
      }
      if (terms.size() < k) break;
      ans += prodsum(terms, k);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}