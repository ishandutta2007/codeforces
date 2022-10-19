#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<int> pq;
    for (int val: a) {
      while (val > n) val /= 2;
      pq.push(val);
    }
    int target = n;
    bool win = 1;
    while (!pq.empty()) {
      int m = pq.top();
      pq.pop();
      if (m < target) {
        win = 0;
        break;
      }
      if (m == target) {
        target--;
      }
      else {
        pq.push(m/2);
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}