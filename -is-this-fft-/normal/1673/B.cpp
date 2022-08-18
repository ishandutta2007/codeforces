#include <iostream>
#include <set>

using namespace std;

void solve () {
  string s;
  cin >> s;

  set<char> us;
  for (char c : s) {
    us.insert(c);
  }

  int m = us.size();
  for (int i = 0; i < (int) s.size() - m; i++) {
    if (s[i] != s[i + m]) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
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