#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<vector<int>> adj;
vector<pll> bounds;

pll solve(int v, int p) {
  pll ans = {0, 0};
  for (int u: adj[v]) {
    if (u != p) {
      pll c = solve(u, v);
      ans.first += max(abs(bounds[v].first-bounds[u].first) + c.first, abs(bounds[v].first-bounds[u].second) + c.second);
      ans.second += max(abs(bounds[v].second-bounds[u].first) + c.first, abs(bounds[v].second-bounds[u].second) + c.second);
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    adj.clear();
    adj.resize(n);
    bounds.resize(n);
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      bounds[i] = {l, r};
    }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    pll ans = solve(0, 0);
    cout << max(ans.first, ans.second) << '\n';
  }
}