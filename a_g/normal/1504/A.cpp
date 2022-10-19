#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-1-i]) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), 'a') == s.size()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << (palindrome(s+'a') ? 'a'+s : s+'a') << '\n';
  }
}