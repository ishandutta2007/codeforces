#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    string ans;
    vector<bool> used(n);
    int l = 0;
    for (char c = '0'; c <= '9'; c++) {
      for (int i = l; i < n; i++) {
        if (s[i] == c) {
          l = i;
          used[i] = 1;
          ans.push_back(c);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        ans.push_back(min<char>(s[i]+1, '9'));
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}