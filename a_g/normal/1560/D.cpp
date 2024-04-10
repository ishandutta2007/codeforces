#include <bits/stdc++.h>
#define ll long long
using namespace std;

int diff(int a, ll b) {
  string s = to_string(a);
  string t = to_string(b);
  int m = s.size();
  int n = t.size();
  int j = 0;
  for (int i = 0; i < m; i++) {
    if (j >= n) break;
    if (s[i] == t[j]) j++;
  }
  return m+n-2*j;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int val;
    cin >> val;
    int ans = 99;
    for (int i = 0; i < 60; i++) {
      ans = min(ans, diff(val, 1LL<<i));
    }
    cout << ans << endl;
  }
}