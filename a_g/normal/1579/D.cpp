#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    priority_queue<pii> pq;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      pq.push({a, i});
    }
    vector<pii> ans;
    while (1) {
      pii x = pq.top();
      pq.pop();
      pii y = pq.top();
      pq.pop();
      if (!y.first) break;
      ans.push_back({x.second, y.second});
      x.first -= 1;
      y.first -= 1;
      pq.push(x);
      pq.push(y);
    }
    cout << ans.size() << '\n';
    for (pii p: ans) {
      cout << p.first << ' ' << p.second << '\n';
    }
  }
}