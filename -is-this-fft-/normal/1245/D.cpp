#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 2e3 + 5;

int dist (int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int x [MAX_N], y [MAX_N];
int to_src [MAX_N];
int K [MAX_N];
int root [MAX_N];
int rnk [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (rnk[u] < rnk[v]) {
    swap(u, v);
  }

  root[v] = u;
  if (rnk[u] == rnk[v]) {
    rnk[u]++;
  }
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 1; i <= N; i++) {
    cin >> to_src[i];
  }
  
  for (int i = 1; i <= N; i++) {
    cin >> K[i];
  }

  vector<pair<ll, pair<int, int>>> edges;
  for (int i = 1; i <= N; i++) {
    edges.push_back({to_src[i], {0, i}});
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      edges.push_back({(ll) dist(x[i], y[i], x[j], y[j]) * (ll) (K[i] + K[j]), {i, j}});
    }
  }

  sort(edges.begin(), edges.end());
  vector<int> pwr;
  vector<pair<int, int>> added;
  ll ans = 0;
  for (auto e : edges) {
    int u = e.second.first;
    int v = e.second.second;

    if (find(u) != find(v)) {
      ans += e.first;
      merge(u, v);

      if (min(u, v) == 0) {
        pwr.push_back(u + v);
      } else {
        added.push_back({u, v});
      }
    }
  }
  
  cout << ans << endl;
  cout << (int) pwr.size() << endl;
  for (int u : pwr) {
    cout << u << " ";
  }
  cout << endl;
  cout << (int) added.size() << endl;
  for (auto pr : added) {
    cout << pr.first << " " << pr.second << '\n';
  }
}