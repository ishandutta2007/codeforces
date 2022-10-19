#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    if (t[0] < t[1] && t[1] < t[2] && count(s.begin(), s.end(), t[0]) && count(s.begin(), s.end(), t[1]) && count(s.begin(), s.end(), t[2])) {
      string u, v, w;
      for (char c: s) {
        if (c < t[1]) u.push_back(c);
        else if (t[1] < c && c <= t[2]) v.push_back(c);
        else w.push_back(c);
      }
      cout << u << v << w << '\n';
    }
    else {
      cout << s << '\n';
    }
  }
}