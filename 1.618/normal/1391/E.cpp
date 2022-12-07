#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define mp make_pair
#define maxn 500005
using namespace std;
typedef long long ll;
typedef long double ldouble;
typedef pair<int, int> P;

int n, m, dep[maxn], par[maxn];
vector<int> deplis[maxn], adj[maxn];
bool vis[maxn];
void dfs(int u) {
  vis[u] = true;
  deplis[dep[u]].push_back(u);
  for (auto v : adj[u]) {
    if (vis[v]) continue;
    dep[v] = dep[u] + 1;
    par[v] = u;
    dfs(v);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    adj[i].clear();
    deplis[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    if (dep[i] >= (n + 1) / 2) {
      cout << "PATH\n";
      cout << dep[i] << "\n";
      for (int u = i; u != 1; u = par[u]) cout << u << " ";
      cout << "1" << endl;
      return;
    }
  }
  vector<P> ans;
  for (int i = 1; i <= n; i++) {
    while (deplis[i].size() >= 2) {
      ans.push_back(mp(deplis[i].back(), *(deplis[i].end() - 2)));
      deplis[i].pop_back();
      deplis[i].pop_back();
    }
  }
  cout << "PAIRING\n";
  cout << ans.size() << "\n";
  for (auto p : ans) cout << p.first << " " << p.second << "\n";
  cout.flush();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}