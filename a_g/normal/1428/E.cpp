#include <bits/stdc++.h>
using namespace std;

long long cost(int x, int y) {
  // split x into y pieces
  return 1LL*(x%y)*(x/y+1)*(x/y+1)+1LL*(y-x%y)*(x/y)*(x/y);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n, 1);
  priority_queue<pair<long long, int>> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pq.emplace(cost(a[i], 1)-cost(a[i], 2), i);
  }
  int steps = k-n;
  while (steps--) {
    pair<long long, int> p = pq.top();
    int i = p.second;
    b[i]++;
    pq.pop();
    pq.emplace(cost(a[i], b[i])-cost(a[i], b[i]+1), i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cost(a[i], b[i]);
  }
  cout << ans << '\n';
}