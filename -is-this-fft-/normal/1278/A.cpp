#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_eq (string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}

bool is_chk (string s, string t) {
  int n = s.size();
  for (int i = 0; i + n <= (int) t.size(); i++) {
    if (is_eq(s, t.substr(i, n))) {
      return true;
    }
  }
  return false;
}

void solve () {
  string s, t;
  cin >> s >> t;

  cout << (is_chk(s, t) ? "YES" : "NO") << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}