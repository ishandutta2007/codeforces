#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+7;

vector<pair<int, int>> inedges[maxn];
vector<pair<int, int>> outedges[maxn];

int n;
set<int> cur;
int ans = 0;

bool dfs(int k) {
  if (n == cur.size()) return 1;
  int next_vtx = 0;
  for (pair<int, int> outedge: outedges[k]) {
    int v = outedge.first;
    bool valid = 1;
    for (pair<int, int> inedge: inedges[v]) {
      if (!cur.count(inedge.first)) {
        valid = 0;
        break;
      }
    }
    if (valid) {
      if (next_vtx) return 0;
      next_vtx = v;
      ans = max(ans, outedge.second);
    }
  }
  cur.insert(next_vtx);
  return dfs(next_vtx);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    inedges[v].push_back({u, i});
    outedges[u].push_back({v, i});
  }
  int winner = -1;
  for (int i = 1; i <= n; i++) {
    if (inedges[i].size() == 0) {
      if (winner != -1) {
        cout << -1 << endl;
        return 0;
      }
      winner = i;
    }
  }
  cur.insert(winner);
  cout << (dfs(winner) ? ans : -1) << endl;
}