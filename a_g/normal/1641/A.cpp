#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    multiset<long long> a;
    for (int i = 0; i < n; i++) {
      long long y;
      cin >> y;
      a.insert(y);
    }
    int ans = 0;
    while (!a.empty()) {
      long long y = *a.begin();
      a.erase(a.begin());
      if (a.count(x*y)) {
        a.erase(a.find(x*y));
      }
      else {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}