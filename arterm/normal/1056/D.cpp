#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

vector<int> g[M];
int n;
int sz[M];

void read() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
}

int dfs(int v) {
  sz[v] = (g[v].empty() ? 1 : 0);
  for (int u : g[v])
    sz[v] += dfs(u);
  return sz[v];
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  dfs(0);
  sort(sz, sz + n);
  for (int i = 0; i < n; ++i)
    cout << sz[i] << " ";

  cout << "\n";
}