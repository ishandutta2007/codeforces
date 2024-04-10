#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e3 + 5;

int root [MAX_N];
int sz [MAX_N];

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
  
  sz[u] += sz[v];
  root[v] = u;
}

int pairc (int n) {
  return (n * (n - 1)) / 2;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
    sz[i] = 1;
  }
  
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> gov (k);
  for (int i = 0; i < k; i++) {
    cin >> gov[i];
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    merge(u, v);
  }

  pair<int, int> bigc = make_pair(-1, -1);
  set<int> govrs;
  for (int c : gov) {
    int r = find(c);
    bigc = max(bigc, make_pair(sz[r], r));
    govrs.insert(r);
  }

  for (int u = 1; u <= n; u++) {
    int r = find(u);
    if (!govrs.count(r)) {
      merge(u, bigc.second);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      ans += pairc(sz[i]);
    }
  }
  ans -= m;

  cout << ans << endl;
}