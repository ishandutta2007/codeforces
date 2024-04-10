#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> indices;
    for (int i = 0; i < n; i++) {
      int u;
      cin >> u;
      indices[u].push_back(i);
    }
    while (k--) {
      int a, b;
      cin >> a >> b;
      if (!indices[a].size() || !indices[b].size()) {
        cout << "NO\n";
        continue;
      }
      cout << (indices[b].back() > indices[a][0] ? "YES" : "NO") << '\n';
    }
  }
}