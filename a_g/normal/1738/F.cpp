#include <bits/stdc++.h>
using namespace std;

int query(int v) {
  cout << "? " << v+1 << endl;
  int u;
  cin >> u;
  return u-1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& x: d) cin >> x;
    vector<int> verts_by_deg(n);
    iota(verts_by_deg.begin(), verts_by_deg.end(), 0);
    sort(verts_by_deg.begin(), verts_by_deg.end(), [&] (int x, int y) {
        return d[x] > d[y];
        });
    vector<int> c(n), used(n);

    int next_color = 1;
    for (int v: verts_by_deg) {
      if (used[v]) continue;
      vector<int> component(1, v);
      used[v] = 1;
      bool is_new = 1;
      for (int i = 0; i < d[v]; i++) {
        int u = query(v);
        if (used[u]) {
          for (int x: component) {
            c[x] = c[u];
          }
          is_new = 0;
          break;
        }
        used[u] = 1;
        component.push_back(u);
      }

      if (is_new) {
        for (int x: component) {
          c[x] = next_color;
        }
        next_color++;
      }
    }

    cout << "!";
    for (int x: c) {
      cout << ' ' << x;
    }
    cout << endl;
  }
}