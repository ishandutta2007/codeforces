#include <bits/stdc++.h>
using namespace std;

string simplify(string& s) {
  string ans;
  if (count(s.begin(), s.end(), 'B') % 2 == 1) {
    ans.push_back('B');
  }
  for (char c: s) {
    if (c != 'B') {
      if (ans.size() && ans.back() == c) {
        ans.pop_back();
      }
      else {
        ans.push_back(c);
      }
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string u, v;
    cin >> u >> v;
    //cout << simplify(u) << " " << simplify(v) << '\n';

    cout << (simplify(u) == simplify(v) ? "YES" : "NO") << '\n';
  }
}