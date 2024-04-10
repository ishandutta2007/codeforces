#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    int ans = -1;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (a.count(x)) ans = x;
    }
    if (ans == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << "1 " << ans << '\n';
  }
}