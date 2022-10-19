#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    pq.emplace(-b, i);
  }
  int low = 1;
  while (pq.size()) {
    int b = -pq.top().first;
    int i = pq.top().second;
    pq.pop();
    low = max(low, b);
    ans[i] = low++;
  }
  for (int x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
}