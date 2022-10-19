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
    for (int& x: a) cin >> x;
    vector<int> ans(n, 1);
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i < n; i++) {
      int d = (a[i-1]-a[i]);
      if (d > 0) {
        auto it = s.lower_bound(d);
        assert(it != s.end());
        ans[*it-1] = i+1;
        s.erase(it);
      }
    }
    for (int x: ans) cout << x << ' ';
    cout << '\n';
  }
}