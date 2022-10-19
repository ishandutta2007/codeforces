#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string t;
  cin >> t;
  int n = (int)t.size();
  int a = count(t.begin(), t.end(), 'a');
  string s = t.substr(0, (n+a)/2);
  string _t = s;
  for (char c: s) {
    if (c != 'a') _t += c;
  }
  cout << (_t == t ? s : ":(") << '\n';
}