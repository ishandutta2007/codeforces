#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int& x: s) cin >> x;
    int l = 0;
    int cur = -1;
    int sz = 0;
    vector<int> ans(n);
    bool win = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == cur) {
        sz++;
      }
      else {
        if (sz == 1) {
          win = 0;
          break;
        }
        for (int j = l; j < l+sz; j++) {
          ans[j] = j+2;
          if (j == l+sz-1) ans[j] = l+1;
        }
        sz = 1;
        cur = s[i];
        l = i;
      }
    }
    if (sz == 1) win = 0;
    for (int j = l; j < l+sz; j++) {
      ans[j] = j+2;
      if (j == l+sz-1) ans[j] = l+1;
    }

    if (!win) {
      cout << "-1\n";
      continue;
    }
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}