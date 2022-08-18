#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void solve () {
  string s;
  cin >> s;
 
  vector<int> bad;
  for (int i = 0; i < (int) s.size() - 2; i ++) {
    if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
      bad.push_back(i);
    }
 
    if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
      bad.push_back(i);
    }
  }
 
  vector<int> ans;
  bool flag = 0;
  for (int i = 0; i < (int) bad.size(); i++) {
    if (i + 1 < (int) bad.size() && bad[i + 1] == 2 + bad[i]) {
      flag = 1;
    } else {
      if (flag) {
        ans.push_back(bad[i]);
        flag = 0;
      } else {
        ans.push_back(bad[i] + 1);
      }
    }
  }
 
  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u + 1 << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i =0 ; i < testc; i++) {
    solve();
  }
}