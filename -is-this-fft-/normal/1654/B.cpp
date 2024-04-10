#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve () {
  string s;
  cin >> s;

  int n = s.size();
  int sta = n;
  set<char> seen;
  for (int i = n - 1; i >= 0; i--) {
    if (!seen.count(s[i])) sta = i;
    seen.insert(s[i]);
  }

  for (int i = sta; i < n; i++) {
    cout << s[i];
  }
  cout << '\n';
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