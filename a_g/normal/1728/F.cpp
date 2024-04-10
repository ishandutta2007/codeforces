#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1728/submission/171434070

const int N = 1005;
int vis[N*N], match[N];
vector<int> G[N*N];
int timer = 1;

bool kuhn(int v) {
  if (vis[v] == timer) return 0;
  vis[v] = timer;
  for (int u: G[v]) {
    if (match[u] == -1 || kuhn(match[u])) {
      match[u] = v;
      return 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      vals.push_back(j*a[i]);
    }
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end())-vals.begin());
  int m = (int)vals.size();
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      int k = lower_bound(vals.begin(), vals.end(), j*a[i])-vals.begin();
      G[k].push_back(i);
    }
  }
  long long ans = 0;
  fill(match, match+n, -1);
  for (int i = 0; i < m; i++) {
    if (kuhn(i)) {
      ans += vals[i];
      timer++;
    }
  }
  cout << ans << '\n';
}