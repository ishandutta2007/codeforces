#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> indices;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') indices.push_back(i);
    }
    int k = indices.size();
    if (k&1 || k == 0) {
      cout << "NO\n";
      continue;
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i+3 < k; i += 2) {
      for (int j = indices[i]; j < indices[i+1]; j++) {
        edges.emplace_back(j, j+1);
      }
    }
    vector<int> path;
    for (int j = indices[k-1]; j != indices[0]; j = (j+1)%n) {
      path.emplace_back(j);
    }
    if (k != 2) path.emplace_back(indices[0]);
    for (int i = 1; i+1 < k; i += 2) {
      for (int j = indices[i]+1; j != indices[i+1]; j++) {
        path.emplace_back(j);
      }
      if (i != k-3) path.emplace_back(indices[i+1]);
    }
    for (int j = indices[k-1]-1; j != indices[k-2]; j--) {
      path.emplace_back(j);
    }
    path.emplace_back(indices[k-2]);

    for (int i = 0; i < (int)path.size()-1; i++) {
      edges.emplace_back(path[i], path[i+1]);
    }

    cout << "YES\n";
    for (pair<int, int>& e: edges) {
      cout << e.first+1 << " " << e.second+1 << '\n';
    }
  }
}