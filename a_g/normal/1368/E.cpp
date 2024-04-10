#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N];
int dep[N];
bool closed[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    while (m--) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
      if (dep[i] >= 2) closed[i] = 1;
      else {
        for (int v: G[i]) {
          dep[v] = max(dep[v], dep[i]+1);
        }
      }
    }

    cout << accumulate(closed+1, closed+n+1, 0) << '\n';
    for (int i = 1; i <= n; i++) {
      if (closed[i]) cout << i << ' ';
    }
    cout << '\n';

    fill(dep, dep+n+1, 0);
    fill(closed, closed+n+1, 0);
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}