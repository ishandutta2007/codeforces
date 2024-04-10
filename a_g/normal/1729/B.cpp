#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string ans;
    while (!s.empty()) {
      char c = s.back();
      s.pop_back();
      if (c == '0') {
        assert((int)s.size() >= 2);
        char d = s.back();
        s.pop_back();
        char e = s.back();
        s.pop_back();
        int k = 10*(e-'0')+(d-'0');
        ans += 'a'+k-1;
      }
      else {
        ans += 'a'+c-'1';
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}