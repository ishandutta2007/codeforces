#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string ans(m, 0);
    for (int i = 0; i < 2*n-1; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        ans[j] ^= s[j];
      }
    }
    cout << ans << '\n';
  }
}