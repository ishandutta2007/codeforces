#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

vector<vector<int>> g;
vector<int> used;

int dfs(int v) {
  used[v] = 1;
  int ans = v;
  for (int u : g[v]) {
    if (!used[u])
      ans = max(ans, dfs(u));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int i = 0;
  int ans = 0;
  while (i < n) {
    int k = dfs(i);
    for (int j = i; j <= k; j++) {
      if (!used[j]) {
        ans++;
        k = max(k, dfs(j));
      }
    }
    i = k + 1;
  }
  cout << ans << endl;
  return 0;
}