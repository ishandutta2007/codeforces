#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<int> p1, p2;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      p1.push(x);
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      p2.push(x);
    }
    int ans = 0;
    while (!p1.empty() && !p2.empty()) {
      int x1 = p1.top(), x2 = p2.top();
      if (x1 == x2) {
        p1.pop();
        p2.pop();
      } else if (x1 > x2) {
        p1.pop();
        p1.push((int)to_string(x1).length());
        ans++;
      } else {
        p2.pop();
        p2.push((int)to_string(x2).length());
        ans++;
      }
    }
    cout << ans << '\n';
  }
}