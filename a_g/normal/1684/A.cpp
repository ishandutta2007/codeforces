#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s.size() == 2) {
      cout << s[1] << '\n';
      continue;
    }
    cout << *min_element(s.begin(), s.end()) << '\n';
  }
}