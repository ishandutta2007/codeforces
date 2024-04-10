#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200010;
 
int n, m, sz;
set <int> unvis;
vector <int> g[N];
 
void dfs (int u) {
  unvis.erase(u); ++sz;
  // cout << u << endl;
  // cout << "## "; for (int x : unvis) cout << x << " "; cout << endl;
  for (int i = 0; i + 1 < g[u].size(); ++i) {
    int l = g[u][i], r = g[u][i + 1];
    while (!unvis.empty()) {
      auto it = unvis.upper_bound(l);
      if (it == unvis.end()) break;
      int v = *it;
      if (v < r) dfs(v); else break;
    }
  }
}
 
int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    g[i].emplace_back(0);
    g[i].emplace_back(n + 1);
    sort(g[i].begin(), g[i].end());
    unvis.emplace(i);
  }
  vector <int> ret;
  while (!unvis.empty()) {
    sz = 0; 
    dfs(*unvis.begin());
    ret.emplace_back(sz);
  }
  cout << ret.size() << '\n';
  sort(ret.begin(), ret.end());
  for (auto it : ret) printf("%d ", it); puts("");
  return 0;
}