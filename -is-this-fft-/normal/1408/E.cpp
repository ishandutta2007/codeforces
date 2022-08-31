#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 3e5 + 5;

const int SET = 2e5 + 5;

int memv (int idx) {
  return idx;
}

int setv (int idx) {
  return SET + idx;
}

typedef long long ll;

ll setcost [MAX_V];
ll memcost [MAX_V];

int root [MAX_V];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int main () {
  for (int i = 0; i < MAX_V; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);

  int m, n;
  cin >> m >> n;

  for (int i = 1; i <= m; i++) {
    cin >> setcost[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> memcost[i];
  }

  vector<pair<ll, pair<int, int>>> edges;
  for (int i = 1; i <= m; i++) {
    int cnt;
    cin >> cnt;

    for (int j = 1; j <= cnt; j++) {
      int x;
      cin >> x;

      edges.push_back(make_pair(setcost[i] + memcost[x], make_pair(setv(i), memv(x))));
    }
  }

  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());

  ll ans = 0;
  for (auto e : edges) {
    ll w = e.first;
    int u = e.second.first;
    int v = e.second.second;

    if (find(u) == find(v)) {
      ans += w;
    } else {
      merge(u, v);
    }
  }

  cout << ans << endl;
}