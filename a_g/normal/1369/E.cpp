#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int w[N], need[N];
vector<pair<int, int>> G[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  vector<bool> used(m+1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].emplace_back(y, i);
    G[y].emplace_back(x, i);
  }
  for (int i = 1; i <= n; i++) {
    need[i] = G[i].size();
  }
  vector<int> que;
  for (int i = 1; i <= n; i++) {
    if (need[i] <= w[i]) {
      que.push_back(i);
    }
  }

  vector<int> ans;
  for (int i = 0; i < (int)que.size(); i++) {
    int v = que[i];
    for (pair<int, int>& e: G[v]) {
      if (!used[e.second]) {
        used[e.second] = 1;
        ans.push_back(e.second);
      }
      int u = e.first;
      need[u]--;
      if (need[u] == w[u]) {
        que.push_back(u);
      }
    }
  }

  if (ans.size() < m) {
    cout << "DEAD\n";
    return 0;
  }
  cout << "ALIVE\n";
  reverse(ans.begin(), ans.end());
  for (int x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
}