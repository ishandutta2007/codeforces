#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> pre;
    pre[0] = 0;
    int cur = 0;
    int l = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cur ^= x;
      if (pre.count(cur)) {
        ans += i-l-1;
        pre.clear();
        l = i;
      }
      pre[cur] = i;
    }
    ans += n-l;
    cout << ans << '\n';
  }
}