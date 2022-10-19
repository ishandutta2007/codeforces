#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> G[N];

int counts[2];

void dfs(int v, int p, int x) {
  counts[x]++;
  for (int u: G[v]) {
    if (u != p) {
      dfs(u, v, 1-x);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1, 0);
  cout << min(counts[0], counts[1]) - 1 << '\n';
}