#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
int n;
vector<vector<int>> nbrs;
vector<vector<int>> dists;
vector<pair<int, int>> edges;

int bfstrees(int x, int y) {
  int dxy = dists[x][y];
  int inbetween = 0;
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (dists[i][x] + dists[i][y] == dxy) inbetween++;
    else {
      int choice = 0;
      for (int j: nbrs[i]) {
        if (dists[j][x] == dists[i][x] - 1 && dists[j][y] == dists[i][y] - 1) {
          choice++;
        }
      }
      if (choice == 0) return 0;
      ans *= choice;
      ans %= MOD;
    }
  }
  if (inbetween > dxy+1) {
    return 0;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m;
  cin >> n >> m;
  nbrs.resize(n);
  dists.resize(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    nbrs[u].push_back(v);
    nbrs[v].push_back(u);
    edges.push_back({u, v});
  }

  for (int v = 0; v < n; v++) {
    dists[v].resize(n);
    set<int> visited;
    queue<pair<int, int>> q;
    visited.insert(v);
    q.push({v, 0});
    while (!q.empty()) {
      int u = q.front().first;
      int d = q.front().second;
      dists[v][u] = d;
      q.pop();
      for (int w: nbrs[u]) {
        if (!visited.count(w)) {
          q.push({w, d+1});
          visited.insert(w);
        }
      }
    }
  }

  int answers[n][n];
  for (int x = 0; x < n; x++) {
    for (int y = x; y < n; y++) {
      int k = bfstrees(x, y);
      answers[x][y] = k;
      answers[y][x] = k;
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << answers[i][j] << " ";
    }
    cout << '\n';
  }
}