#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    vector<vector<int>> indices(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      indices[a[i]].push_back(i);
    }
    vector<int> que;
    for (int i = 1; i <= n; i++) {
      if (indices[i].size()) que.push_back(i);
    }
    sort(que.begin(), que.end(), [&] (int x, int y) {return indices[x].size() > indices[y].size();});
    while (que.size()) {
      int m = que.size();
      for (int i = 0; i < m; i++) {
        ans[indices[que[i]].back()] = que[(i+1)%m];
      }
      for (int i = 0; i < m; i++) {
        indices[que[i]].pop_back();
      }
      while (que.size() && (indices[que.back()].size() == 0)) {
        que.pop_back();
      }
    }
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}