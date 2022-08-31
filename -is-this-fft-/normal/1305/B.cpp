#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();

  vector<int> ans;
  int lptr = 0, rptr = n - 1;
  while (lptr < rptr && lptr < n && rptr >= 0) {
    while (lptr < n && s[lptr] != '(') {
      lptr++;
    }

    while (rptr >= 0 && s[rptr] != ')') {
      rptr--;
    }

    if (lptr >= rptr || lptr >= n || rptr < 0) {
      break;
    }

    ans.push_back(lptr + 1);
    ans.push_back(rptr + 1);
    lptr++;
    rptr--;
  }

  if (ans.empty()) {
    cout << 0 << endl;
    return 0;
  }
  
  sort(ans.begin(), ans.end());

  cout << 1 << endl;
  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}