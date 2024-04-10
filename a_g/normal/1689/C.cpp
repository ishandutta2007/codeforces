#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;
int depth[N];
vector<int> G[N];
int children[N];

void dfs(int v, int p) {
  if (v != p) {
    children[p]++;
    depth[v] = depth[p]+1;
  }
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  depth[1] = 1;
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
    int minloss = n;
    for (int i = 1; i <= n; i++) {
      if (children[i] == 1) {
        minloss = min(minloss, 2*depth[i]);
      }
      else if (children[i] == 0) {
        minloss = min(minloss, 2*depth[i]-1);
      }
    }
    cout << n-minloss << '\n';

    
    fill(children+1, children+n+1, 0);
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}