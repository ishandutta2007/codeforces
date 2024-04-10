#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;

int n, m;
vector<pair<int, int>> g[maxn];
int from[maxn], eflow[maxn];
int vflow[maxn];
int ans[maxn];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, f;
    cin >> u >> v >> f;
    --u; --v;
    from[i] = u;
    eflow[i] = f;
    vflow[u] += f;
    vflow[v] += f;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  for(int i = 1; i < n - 1; i++)
    vflow[i] /= 2;
  queue<int> q;
  q.push(0);
  vector<bool> was(n, false);
  was[0] = true;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(pair<int, int> edge : g[v]) {
      int to = edge.first;
      int epos = edge.second;
      if(was[to])
        continue;
      if(to == from[epos])
        ans[epos] = 1;
      vflow[to] -= eflow[epos];
      if(vflow[to] == 0) {
        was[to] = true;
        q.push(to);
      }
    }
  }
  for(int i = 0; i < m; i++)
    cout << ans[i] << '\n';
}