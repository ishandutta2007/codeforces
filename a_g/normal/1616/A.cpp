#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a = abs(a);
      if (!m[a]) {
        ans++;
      }
      else {
        if (m[a] == 1 && a != 0) ans++;
      }
      m[a]++;
    }
    cout << ans << '\n';
  }
}