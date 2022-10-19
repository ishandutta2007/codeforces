#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[j][i];
    }
  }
  vector<int> best(m);
  iota(best.begin(), best.end(), 0);
  for (int i = 0; i < n - 1; ++i) {
    vector<pair<int, int>> d;
    int s = 0;
    for (int j = 0; j < m; ++j) {
      d.emplace_back(a[i][j] - a[n - 1][j], j);
      s += d.back().first;
    }
    sort(d.begin(), d.end());
    vector<int> cur;
    for (int j = 0; j < m; ++j) {
      if (s >= 0) {
        if (best.size() > cur.size()) {
          best = cur;
        }
        break;
      }
      s -= d[j].first;
      cur.push_back(d[j].second);
    }
  }
  cout << best.size() << '\n';
  for (int x : best) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
}