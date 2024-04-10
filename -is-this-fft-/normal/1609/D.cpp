#include <iostream>
#include <vector>
#include <algorithm>

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

  root[u] = v;
  sz[v] += sz[u];
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    sz[i] = 1;
    root[i] = i;
  }

  int frees = 0;
  for (int i = 0; i < qc; i++) {
    int u, v;
    cin >> u >> v;

    if (find(u) == find(v)) {
      frees++;
    } else {
      merge(u, v);
    }

    vector<int> csz;
    for (int k = 1; k <= n; k++) {
      if (find(k) == k) {
        csz.push_back(sz[k]);
      }
    }

    sort(csz.begin(), csz.end(), greater<int>());
    int ans = 0;
    for (int j = 0; j < min((int) csz.size(), frees + 1); j++) {
      ans += csz[j];
    }
    ans--;

    cout << ans << '\n';
  }
}