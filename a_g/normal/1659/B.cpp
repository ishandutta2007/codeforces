#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k&1) {
      for (char &c: s) {
        if (c == '0') c = '1';
        else c = '0';
      }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (!k) break;
      if (s[i] == '0') {
        s[i] = '1';
        ans[i] = 1;
        k--;
      }
    }
    if (k) {
      ans[n-1] += k;
      if (k&1) s[n-1] = '0';
    }
    cout << s << '\n';
    for (int i: ans) {
      cout << i << " ";
    }
    cout << '\n';
  }
}