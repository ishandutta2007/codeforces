#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  string t;
  for (int i = 0; 2*i+3 < n; i += 2) {
    for (char c: {'a', 'b', 'c'}) {
      bool l = (s[i] == c || s[i+1] == c);
      bool r = (s[n-1-i] == c || s[n-2-i] == c);
      if (l && r) {
        t.push_back(c);
        break;
      }
    }
  }
  cout << t;
  if (2*t.size() < n/2) cout << s[n/2];
  reverse(t.begin(), t.end());
  cout << t << '\n';
}