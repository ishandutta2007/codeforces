#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int z = 1;
  map<string, int> ans;
  for (char x = 'a'; x <= 'z'; x++) {
    for (char y = 'a'; y <= 'z'; y++) {
      if (x == y) continue;
      string s;
      s.push_back(x);
      s.push_back(y);
      ans[s] = z++;
    }
  } 
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << ans[s] << '\n';
  }
}