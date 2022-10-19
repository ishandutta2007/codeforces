#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    priority_queue<pair<int, int>> pq;
    vector<int> res(n);
    for (int i = 0; i < m; i++) {
      pq.push({0, i});
    }
    for (int i = 0; i < n; i++) {
      auto foo = pq.top();
      pq.pop();
      res[i] = foo.second;
      foo.first -= a[i];
      pq.push(foo);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << res[i] + 1 << ' ';
    cout << '\n';
  }

  return 0;
}