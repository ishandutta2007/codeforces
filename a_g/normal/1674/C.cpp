#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    if (t == "a") {
      cout << "1\n";
      continue;
    }
    if (count(t.begin(), t.end(), 'a') > 0) {
      cout << "-1\n";
      continue;
    }
    cout << (1LL<<(s.size())) << '\n';
  }
}