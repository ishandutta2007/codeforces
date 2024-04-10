#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cur = -1;
    int sz = 0;
    int ans = 1;
    while (n--) {
      int a;
      cin >> a;
      if (cur == a) sz++;
      else {
        ans = max(ans, sz);
        cur = a;
        sz = 1;
      }
    }
    ans = max(ans, sz);
    cout << ans << '\n';
  }
}