#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int b = 0; b < 7; b++) {
      vector<int> l1, l2;
      for (int v = 1; v <= n; v++) {
        if ((v>>b)&1) l1.push_back(v);
        else l2.push_back(v);
      }
      if (l1.empty() || l2.empty()) continue;
      cout << l1.size() << ' ' << l2.size();
      for (int v: l1) cout << ' ' << v;
      for (int v: l2) cout << ' ' << v;
      cout << endl;
      int d;
      cin >> d;
      ans = max(ans, d);
    }
    cout << "-1 " << ans << endl;
  }
}