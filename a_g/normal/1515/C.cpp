#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, x;
    cin >> n >> m >> x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= m; i++) {
      pq.emplace(0, i);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      pair<int, int> p = pq.top();
      cout << p.second << ' ';
      pq.pop();
      pq.emplace(p.first+h, p.second);
    }
    cout << '\n';
  }
}