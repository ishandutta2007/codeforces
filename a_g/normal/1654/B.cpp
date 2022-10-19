#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    set<char> t;
    int n = s.size();
    int start = n;
    for (int i = n-1; i >= 0; i--) {
      if (!t.count(s[i])) {
        start = i;
        t.insert(s[i]);
      }
    }
    cout << s.substr(start) << '\n';
  }
}