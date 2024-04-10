#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll sz [MAX_N];
int root [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) return;

  root[u] = v;
  sz[v] += sz[u];
}

ll arr [MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    sz[i] = 1;
    root[i] = i;
  }

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<pair<ll, pair<int, int>>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    edges.push_back(make_pair(min(arr[u], arr[v]), make_pair(u, v)));
  }

  sort(edges.rbegin(), edges.rend());

  ll ans = 0;
  for (auto e : edges) {
    ll w = e.first;
    int u = e.second.first;
    int v = e.second.second;

    u = find(u);
    v = find(v);
    if (u != v) {
      ans += w * sz[u] * sz[v];
      merge(u, v);
    }
  }

  ll pc = (ll) n * (ll) (n - 1);
  cout << fixed << setprecision(12) << 2 * (double) ans / (double) pc << endl;
}