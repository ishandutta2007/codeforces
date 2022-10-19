#include <bits/stdc++.h>

using namespace std;

const int M = 200200;

vector<int> h[M], g[M], ans[M];
int n, m;
bool used[M];

void read() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    h[x].push_back(i + 1);
    h[y].push_back(i + 1);
  }
}

void dfs(int v, int c) {
  used[v] = true;
  for (int i = 0; i < (int) g[v].size(); ++i) {
    int to = g[v][i];
    int id = h[v][i];
    if (used[to])
      continue;
    c = (c + 1) % m;
    ans[c].push_back(id);
    dfs(to, c);
  }
}

void kill() {
  m = 0;
  for (int i = 1; i <= n; ++i)
    m = max(m, (int) g[i].size());
  dfs(1, 0);

  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    cout << ans[i].size() << " ";
    for (int x : ans[i])
      cout << x << " ";
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
  return 0;
}