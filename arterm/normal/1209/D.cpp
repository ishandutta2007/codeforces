#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n;
int m;
vector<int> g[M];
bool u[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

int dfs(int v) {
  u[v] = true;
  int ans = 1;
  for (int to : g[v])
    if (!u[to])
      ans += dfs(to);
  return ans;
}

void kill() {
  int ans = 0;
  for (int v = 0; v < n; ++v) {
    if (!u[v])
      ans += dfs(v) - 1;
  }
  cout << m - ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}