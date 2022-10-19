#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != '1' || s[n-1] != '1' || count(s.begin(), s.end(), '0')%2 == 1) {
      cout << "NO\n";
      continue;
    }
    string ans[2];
    int z = count(s.begin(), s.end(), '1');
    int cur = 0;
    bool x = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (cur++ < z/2) {
          ans[0] += "(";
          ans[1] += "(";
        }
        else {
          ans[0] += ")";
          ans[1] += ")";
        }
      }
      else {
        ans[x] += "(";
        ans[1-x] += ")";
        x = 1-x;
      }
    }
    cout << "YES\n";
    cout << ans[0] << '\n' << ans[1] << '\n';
  }
}