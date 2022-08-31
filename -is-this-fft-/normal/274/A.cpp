#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int root [MAX_N];
int sz [MAX_N];

int find (int u) {
  if (u != root[u]) {
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

int main () {
  int n, K;
  cin >> n >> K;

  map<ll, int> idx;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    idx[x] = i;
  }

  for (int i = 0; i < n; i++) {
    root[i] = i;
    sz[i] = 1;
  }

  for (auto pr : idx) {
    auto nxt = pr.first * K;
    if (idx.count(nxt)) {
      merge(idx[nxt], pr.second);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (find(i) == i) {
      ans += (sz[i] + 1) / 2;
    }
  }

  cout << ans << endl;
}