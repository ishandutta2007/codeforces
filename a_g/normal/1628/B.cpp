#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> bigrams;
    set<string> trigrams;
    bool win = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      if (s[i][0] == s[i].back()) {
        win = 1;
      }
      if (s[i].size() >= 2) {
        string t = s[i].substr(s[i].size()-2, 2);
        reverse(t.begin(), t.end());
        if (bigrams.count(t)) win = 1;
        if (s[i].size() == 2) {
          bigrams.insert(s[i]);
          for (char c = 'a'; c <= 'z'; c++) {
            string u = t + string(1, c);
            if (trigrams.count(u)) win = 1;
          }
        }
      }
      if (s[i].size() == 3) {
        string t = s[i];
        reverse(t.begin(), t.end());
        if (trigrams.count(t)) win = 1;
        trigrams.insert(s[i]);
      }
    }

    cout << (win ? "YES" : "NO") << '\n';

  }
}