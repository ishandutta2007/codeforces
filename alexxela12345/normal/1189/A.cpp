#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int cnt1 = 0, cnt0 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt0++;
    } else {
      cnt1++;
    }
  }
  if (cnt0 == cnt1) {
    cout << 2 << endl;
    cout << s[0] << " ";
    for (int i = 1; i < n; i++) {
      cout << s[i];
    }
    cout << endl;
  } else {
    cout << 1 << endl << s << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}