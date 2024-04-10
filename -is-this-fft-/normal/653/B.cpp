#include <iostream>
#include <vector>
#include <string>
#include <set>
const int MAX_LEN = 40;

using namespace std;

vector<string> nxt [6];
 set<string> ans [6];



int main () {
  int ilen, queryc;
  cin >> ilen >> queryc;

  for (int i = 0; i < queryc; i++) {
    string ln;
    char sh;
    cin >> ln >> sh;
    nxt[sh - 'a'].push_back(ln);
  }

  ans[0].insert("a");
  for (int i = 0; i < 5; i++) {
    for (auto j = ans[i].begin(); j != ans[i].end(); j++) {
      string st = *j;
      for (int k = 0; k < nxt[st[0] - 'a'].size(); k++) {
	ans[i + 1].insert(nxt[st[0] - 'a'][k] + st.substr(1));
      }
    }
  }

  cout << ans[ilen - 1].size() << endl;
}