#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
  vector<int> root, rnk;

public:
  DSU (int _vertexc) {
    root = vector<int> (_vertexc);
    rnk = vector<int> (_vertexc, 0);
    for (int i = 0; i < _vertexc; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (u != root[u]) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
      return;
    }

    if (rnk[u] < rnk[v]) {
      swap(u, v);
    }

    root[v] = u;

    if (rnk[u] == rnk[v]) {
      rnk[u]++;
    }
  }
};

int ask (int u) {
  cout << "? " << u << endl;
  int resp;
  cin >> resp;
  return resp;
}

void solve () {
  int n;
  cin >> n;

  vector<int> deg (n + 1);
  vector<pair<int, int>> bydeg;
  for (int i = 1; i <= n; i++) {
    cin >> deg[i];
    bydeg.push_back({deg[i], i});
  }

  sort(bydeg.begin(), bydeg.end());

  vector<int> used (n + 1, 0);
  DSU dsu (n + 1);
  while (!bydeg.empty()) {
    int u = bydeg.back().second;
    bydeg.pop_back();

    if (used[u]) {
      continue;
    }

    for (int i = 0; i < deg[u]; i++) {
      int nxt = ask(u);
      dsu.merge(u, nxt);

      if (used[nxt]) {
        break;
      }

      used[nxt] = 1;
    }

    used[u] = 1;
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << dsu.find(i) << " ";
  }
  cout << endl;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}