#include <iostream>
#include <algorithm>

using namespace std;

bool special (char s, char t) {
  if (s == 'b' && t == 'c') {
    return false;
  }

  if (s == 'c' && t == 'b') {
    return true;
  }

  return s < t;
}

void solve () {
  string s, t;
  cin >> s >> t;

  if (t == string("abc") && s.find('a') != string::npos) {
    sort(s.begin(), s.end(), special);
  } else {
    sort(s.begin(), s.end());
  }

  cout << s << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}