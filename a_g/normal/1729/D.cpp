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
    multiset<int> pos;
    vector<int> neg;
    for (int& x: a) cin >> x;
    for (int& x: a) {
      int y;
      cin >> y;
      x = y-x;
      if (x < 0) neg.push_back(-x);
      else pos.insert(x);
    }
    int ans = 0;
    sort(neg.begin(), neg.end());
    for (int x: neg) {
      auto it = pos.lower_bound(x);
      if (it != pos.end()) {
        ans++;
        pos.erase(it);
      }
    }
    ans += (int)pos.size()/2;
    cout << ans << '\n';
  }
}