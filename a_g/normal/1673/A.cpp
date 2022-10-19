#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int tot = 0;
    for (char c: s) {
      tot += c-'a'+1;
    }
    if (s.length()&1) {
      tot -= 2*(min(s[0], s.back())-'a'+1);
    }
    if (tot > 0) {
      cout << "Alice " << tot << '\n';
    }
    else {
      cout << "Bob " << -tot << '\n';
    }
  }
}