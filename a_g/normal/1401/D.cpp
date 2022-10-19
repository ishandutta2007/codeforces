#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+2;
vector<int> G[N];
int sz[N];

void dfs(int v, int p) {
  sz[v] = 1;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
    sz[v] += sz[u];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, 1);
    vector<long long> coeffs;
    for (int i = 2; i <= n; i++) {
      coeffs.push_back(1LL*sz[i]*(n-sz[i]));
    }
    sort(coeffs.begin(), coeffs.end());
    int m;
    cin >> m;
    vector<int> p(m);
    for (int& x: p) cin >> x;
    sort(p.begin(), p.end());
    while ((int)p.size() > n-1) {
      int x = p.back();
      p.pop_back();
      p.back() = 1LL*p.back()*x % MOD;
    }
    m = (int)p.size();
    int ans = 0;
    for (int i = 0; i < n-1-m; i++) {
      ans = (ans+coeffs[i])%MOD;
    }
    for (int i = 0; i < m; i++) {
      ans = (ans+(coeffs[n-2-i]%MOD)*p[m-1-i])%MOD;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}