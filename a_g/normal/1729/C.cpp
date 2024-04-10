#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<vector<int>> indices(26);
    for (int i = 0; i < (int)s.size(); i++) {
      indices[s[i]-'a'].push_back(i+1);
    }
    int u = s[0]-'a';
    int v = s.back()-'a';
    vector<int> ans;
    int sgn = (u > v ? -1 : 1);
    for (int i = u; sgn*(v-i) >= 0; i += sgn) {
      for (int x: indices[i]) ans.push_back(x);
    }
    cout << abs(u-v) << ' ' << ans.size() << '\n';
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}