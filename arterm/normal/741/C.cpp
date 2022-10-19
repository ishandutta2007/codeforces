#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 200200;

int n;
int a[M], b[M];
vector<int> g[M];
bool u[M];
int c[M];

void add(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

void dfs(int v, int col=0) {
  u[v] = true;
  c[v] = col;
  for (int to : g[v])
    if (!u[to])
      dfs(to, col ^ 1);
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    a[i] = u, b[i] = v;
  }
}

void kill() {
  for (int i = 0; i < n; ++i) {
    add(a[i], b[i]);
    add(2 * i, 2 * i + 1);
  }

  for (int i = 0; i < 2 * n; ++i)
    assert(g[i].size() == 2);

  for (int v = 0; v < 2 * n; ++v)
    if (!u[v])
      dfs(v, 0);

  for (int i = 0; i < n; ++i) {
    cout << c[a[i]] + 1 << " " << c[b[i]] + 1 << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}