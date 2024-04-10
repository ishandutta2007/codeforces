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
    set<int> s;
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (s.count(a[i])) {
        ans = i+1;
        break;
      }
      s.insert(a[i]);
    }
    cout << ans << '\n';
  }
}