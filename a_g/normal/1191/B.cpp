#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  set<string> s({a, b, c});
  if (s.size() < 3) {
    cout << s.size()-1 << endl;
    return 0;
  }
  vector<char> symbols({'m', 'p', 's'});
  int ans = 2;
  for (char i = '1'; i < '8'; i++) {
    for (char c: symbols) {
      int hits = 0;
      for (int j = 0; j < 3; j++) {
        if (s.count(string({(char)(i+j), c}))) {
          hits++;
        }
      }
      ans = min(ans, 3-hits);
    }
  }
  cout << ans << endl;
}