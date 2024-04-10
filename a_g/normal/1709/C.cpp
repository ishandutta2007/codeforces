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
    int emp = 0;
    vector<int> indices;
    for (int i = 0; i < (int)s.size(); i++) {
      char c = s[i];
      if (c == '(') tot++;
      if (c == ')') tot--;
      if (c == '?') {
        emp++;
        indices.push_back(i);
      }
    }
    int open = (emp-tot)/2;
    int close = (emp+tot)/2;
    if (open == 0 || close == 0) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i < open-1; i++) {
      s[indices[i]] = '(';
    }
    s[indices[open-1]] = ')';
    s[indices[open]] = '(';
    for (int i = open+1; i < emp; i++) {
      s[indices[i]] = ')';
    }
    tot = 0;
    bool ok = 1;
    for (char c: s) {
      if (c == '(') tot++;
      if (c == ')') tot--;
      if (tot < 0) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "NO" : "YES") << '\n';
  }
}