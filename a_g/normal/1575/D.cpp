#include <bits/stdc++.h>
#define ll long long
using namespace std;

const string digits = "0123456789";

int solve(string s) {
  int m = s.length();
  ll ans = 0;
  if (s.find('X') != string::npos) {
    for (char c: digits) {
      string n = s;
      replace(n.begin(), n.end(), 'X', c);
      ans += solve(n);
    }
    return ans;
  }

  // leading zero
  if (m > 1 && s[0] == '0') {
    return 0;
  }

  // handle one digit separately
  if (m == 1) {
    if (s[0] == '0' || s[0] == '_' || s[0] == 'X') {
      return 1;
    }
    else {
      return 0;
    }
  }

  if (s[m-1] == '_') {
    for (char c: digits) {
      string n = s;
      n[m-1] = c;
      ans += solve(n);
    }
    return ans;
  }

  if (s[m-2] == '_') {
    for (char c: digits) {
      string n = s;
      n[m-2] = c;
      ans += solve(n);
    }
    return ans;
  }

  if (stoi(s.substr(m-2), nullptr, 10) % 25 != 0) {
    return 0;
  }
  ans = 1;
  for (int i = 0; i < m-2; i++) {
    if (s[i] == '_') {
      if (i == 0) ans *= 9;
      else ans *= 10;
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s;
  cin >> s;
  cout << solve(s) << endl;
}