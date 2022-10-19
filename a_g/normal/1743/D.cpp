#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int l = 0;
  while (l < n && s[l] == '0') l++;
  n -= l;
  s = s.substr(l);
  if (n == 0) {
    cout << "0\n";
    return 0;
  }

  int start = 0;
  while (start < n && s[start] == '1') start++;

  if (start == n) {
    cout << s << '\n';
    return 0;
  }

  int len = n-start;
  string ans = s;
  for (int i = 0; i+len <= n; i++) {
    // s[start:n] |= s[i:i+len]
    string cand = s;
    for (int j = 0; j < len; j++) {
      if (s[i+j] == '1') cand[start+j] = '1';
    }
    ans = max(ans, cand);
  }
  cout << ans << '\n';
}