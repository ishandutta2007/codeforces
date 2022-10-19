#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  set<string> shifts;
  for (int i = 0; i < (int)s.size(); i++) {
    shifts.insert(s);
    s = s.substr(1) + s[0];
  }
  cout << shifts.size() << '\n';
}