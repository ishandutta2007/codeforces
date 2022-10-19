#include <bits/stdc++.h>
using namespace std;

string s[3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    bool ok = 0;
    for (int i = 0; i < 3 && !ok; i++) {
      for (int j = i+1; j < 3 && !ok; j++) {
        int c1 = count(s[i].begin(), s[i].end(), '0');
        int c2 = count(s[j].begin(), s[j].end(), '0');
        bool good = 0;
        char c = ' ';
        if (c1 <= n && c2 <= n) {
          good = 1;
          c = '1';
        }
        else if (c1 >= n && c2 >= n) {
          good = 1;
          c = '0';
        }
        if (good) {
          string ans;
          while (s[i].size() || s[j].size()) {
            while (s[i].size() && s[i].back() != c) {
              ans += s[i].back();
              s[i].pop_back();
            }
            while (s[j].size() && s[j].back() != c) {
              ans += s[j].back();
              s[j].pop_back();
            }
            if (s[i].size() || s[j].size()) {
              ans += c;
              if (s[i].size()) {
                assert(s[i].back() == c);
                s[i].pop_back();
              }
              if (s[j].size()) {
                assert(s[j].back() == c);
                s[j].pop_back();
              }
            }
          }
          reverse(ans.begin(), ans.end());
          cout << ans << '\n';
          ok = 1;
        }
      }
    }
    if (!ok) assert(0);
  }
}