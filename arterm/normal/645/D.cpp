#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e5 + 10;

vector<int> g[M];
vector<int> ord;
int n, m;
bool used[M];
int u[M], v[M];
int p[M];

void dfs(int v) {
  used[v] = true;
  for (int to : g[v])
    if (!used[to])
      dfs(to);
  ord.push_back(v);
}

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
    g[u[i]].push_back(v[i]);
  }
}

void kill() {
  for (int i = 0; i < n; ++i)
    if (!used[i])
      dfs(i);

  for (int i = 0; i < n; ++i) {
    p[ord[i]] = i;
    //cerr << ord[i] << " ";
  }
  //cerr << endl;

  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    int diff = p[u[i]] - p[v[i]];
    assert(diff > 0);
    if (diff == 1)
      ++cnt;
    if (cnt == n - 1) {
      cout << i + 1 << endl;
      exit(0);
    }
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
}