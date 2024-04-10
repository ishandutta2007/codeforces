#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[2][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  bool flag = T == 10000;
  while (T--) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c[i][j] = 0;
      }
    }
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
      c[s[i]-'0'][t[i]-'0']++;
    }
    int ans = 1e9;
    if (c[0][1] == c[1][0]) {
      ans = 2*c[0][1];
    }
    if (c[1][1]-c[0][0] == 1) {
      ans = min(ans, 1+2*c[0][0]);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
  }
}