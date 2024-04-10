#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> prv;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (prv.count(a)) {
        ans = max(ans, n-(i-prv[a]));
      }
      prv[a] = i;
    }
    cout << ans << '\n';
  }
}