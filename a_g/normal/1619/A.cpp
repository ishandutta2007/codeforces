#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    bool yes = 0;
    if (s.size() % 2 == 0) {
      int k = s.size()/2;
      string t = s.substr(0, k);
      if (s == t+t) yes = 1;
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
}