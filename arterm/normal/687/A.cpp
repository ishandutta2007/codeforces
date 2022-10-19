#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

int n, m;
vector<int> g[M];
bool used[M];
int c[M];
vector<pair<int, int>> e;

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    e.emplace_back(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs(int v, int col) {
  used[v] = true;
  c[v] = col;

  for (int to : g[v])
    if (!used[to])
      dfs(to, col ^ 1);
}


void kill() {
  for (int v = 0; v < n; ++v)
    if (!used[v])
      dfs(v, 0);

  bool ans = true;


  for (auto p : e)
    if (c[p.first] == c[p.second])
      ans = false;

  if (!ans) {
    cout << "-1\n";
    return;
  }

  vector<int> a[2];

  for (int v = 0; v < n; ++v)
    a[c[v]].push_back(v + 1);

  for (int i = 0; i < 2; ++i) {
    cout << a[i].size() << endl;
    for (int x : a[i])
      cout << x << " ";
    cout << endl;
  }

}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}