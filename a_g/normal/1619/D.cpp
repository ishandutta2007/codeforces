#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> t[i][j];
      }
    }

    vector<int> b(m);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        b[j] = max(b[j], t[i][j]);
      }
    }
    int u = *min_element(b.begin(), b.end());
    int v = 0;
    for (int i = 0; i < n; i++) {
      t[i].erase(find(t[i].begin(), t[i].end(), *max_element(t[i].begin(), t[i].end())));
      v = max(v, *max_element(t[i].begin(), t[i].end()));
    }
    cout << min(u, v) << '\n';
  }
}