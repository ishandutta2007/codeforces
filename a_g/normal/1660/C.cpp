#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    set<char> occ;
    int ans = 0;
    for (char c: s) {
      if (occ.count(c)) {
        ans += (int)occ.size()-1;
        occ.clear();
      }
      else {
        occ.insert(c);
      }
    }
    ans += occ.size();
    cout << ans << '\n';
  }
}