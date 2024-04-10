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
    if (s[0] != '9') {
      for (char c: s) {
        cout << (char)('0'+'9'-c);
      }
      cout << '\n';
      continue;
    }
    vector<int> z(n+1);
    for (int i = 0; i < n; i++) {
      z[i] = s[n-1-i]-'0';
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (z[i] <= 1) ans[i] = 1-z[i];
      else {
        ans[i] = 11-z[i];
        z[i+1]++;
      }
    }
    for (int i = n-1; i >= 0; i--) {
      cout << ans[i];
    }
    cout << '\n';
  }
}