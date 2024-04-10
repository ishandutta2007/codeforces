#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> indices(2);
  vector<vector<int>> ans(2);
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    indices[p[i].first < p[i].second].push_back(i);
  }
  for (int i = 0; i < 2; i++) {
    sort(indices[i].begin(), indices[i].end(), [&] (int x, int y) {
      return (i ? 1 : -1)*(p[x].second-p[y].second) > 0;
        });
    for (int j: indices[i]) {
      if (!ans[i].size() || (i ? 1 : -1)*(p[j].first-p[ans[i].back()].second) < 0) {
        ans[i].push_back(j);
      }
    }
  }
  vector<int> v = (ans[0].size() > ans[1].size() ? ans[0] : ans[1]);
  cout << v.size() << '\n';
  for (int i: v) {
    cout << i+1 << ' ';
  }
  cout << '\n';
}