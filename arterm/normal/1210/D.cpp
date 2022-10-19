#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n, m;
vector<int> g[M];
ll ans = 0;
ll deg[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);
    g[u].push_back(v);

    deg[u]++;
    deg[v]++;
  }
}

ll f(int v) {
  ll x = g[v].size();
  return x * (deg[v] - x);
}

void kill() {
  for (int v = 0; v < n; ++v)
    ans += f(v);

  cout << ans << "\n";

  int q;
  cin >> q;
  while (q--) {
    int v;
    cin >> v;
    --v;

    ans -= f(v);
    for (int u : g[v]) {
      ans -= f(u);
      g[u].push_back(v);
      ans += f(u);
    }
    g[v].clear();
    cout << ans << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}