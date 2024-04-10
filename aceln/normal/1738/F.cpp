#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int query(int x) {
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> d(n + 1), color(n + 1);

    set<pii> s;

    for (int i = 1; i <= n; i++) {
      cin >> d[i];
      s.insert({d[i], i});
    }
    while (!s.empty()) {
      auto [degu, u] = *(--s.end());
      s.erase({degu, u});

      color[u] = u;

      vector<int> vv;
      for (int i = 1; i <= d[u]; i++) {
        int v = query(u);
        vv.emplace_back(v);
        if (color[v] != 0) {
          for (int j : vv)
            color[j] = color[v];
          color[u] = color[v];
          break;
        } else {
          color[v] = u;
          s.erase({d[v], v});
        }
      }
    }
    cout << '!';
    for (int i = 1; i <= n; i++)
      cout << ' ' << color[i];
    cout << endl;
  }
}