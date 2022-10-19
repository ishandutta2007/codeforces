#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int indeg[N], min_before[N], min_after[N];
bool b[N];
vector<int> G[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  iota(min_before, min_before+n+1, 0);
  iota(min_after, min_after+n+1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    indeg[v]++;
  }
  vector<int> que;
  for (int i = 1; i <= n; i++) {
    if (!indeg[i]) que.push_back(i);
  }

  for (int i = 0; i < (int)que.size(); i++) {
    int v = que[i];
    for (int u: G[v]) {
      indeg[u]--;
      min_before[u] = min(min_before[u], min_before[v]);
      if (!indeg[u]) {
        que.push_back(u);
      }
    }
  }

  if (que.size() != n) {
    cout << "-1\n";
    return 0;
  }

  for (int i = n-1; i >= 0; i--) {
    int v = que[i];
    for (int u: G[v]) {
      min_after[v] = min(min_after[u], min_after[v]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i > min(min_before[i], min_after[i])) {
      b[i] = 1;
    }
  }
  cout << n-accumulate(b+1, b+n+1, 0) << '\n';
  for (int i = 1; i <= n; i++) {
    cout << (b[i] ? 'E' : 'A');
  }
  cout << '\n';
}