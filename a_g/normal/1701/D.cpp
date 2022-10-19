#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> needs(n);
    for (int i = 1; i <= n; i++) {
      int b;
      cin >> b;
      int low = i/(b+1)+1;
      int high = (b ? i/b : n);
      needs[low-1].emplace_back(-high, i-1);
    }
    priority_queue<pair<int, int>> pq;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      for (pair<int, int>& p: needs[i]) pq.push(p);
      ans[pq.top().second] = i+1;
      pq.pop();
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i+1==n];
    }
  }
}