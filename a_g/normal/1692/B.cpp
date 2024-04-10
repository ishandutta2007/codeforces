#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    int ans = a.size();
    if ((n-ans)&1) ans--;
    cout << ans << '\n';
  }
}