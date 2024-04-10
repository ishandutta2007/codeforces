#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

int n, m;
int r[M];
vector<int> g[M], h[M];
int val[M];
bool u[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    r[i] = 1 - r[i];
  }

  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      --x;
      h[x].push_back(i);
      g[i].push_back(x);
    }
  }
}

void dfs(int v) {
  if (u[v])
    return;

  u[v] = true;
  int cur = r[v];
  int to = -1;
  int cnt = 0;
  for (int x : h[v])
    if (val[x] != -1) {
      cur ^= val[x];
    } else {
      to = x;
      ++cnt;
    }

  if (cnt == 1) {
    val[to] = cur;
    for (int u : g[to])
      dfs(u);
  } else if (cnt == 2) {
    int x = h[v][0];
    int y = h[v][1];
    val[x] = r[v];
    val[y] = 0;
    for (int to : {x, y})
      for (int u : g[to])
        dfs(u);
  }
}

void kill() {
  fill(val, val + m, -1);
  for (int v = 0; v < n; ++v)
    dfs(v);
  
  bool ans = true;
  for (int v = 0; v < n; ++v) {
    int x = h[v][0];
    int y = h[v][1];
    assert(val[x] >= 0 && val[y] >= 0);
    int cur = val[x] ^ val[y];
    ans &= cur == r[v];
  }
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}