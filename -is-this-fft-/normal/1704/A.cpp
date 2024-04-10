#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());

  for (int i = 0; i < m - 1; i++) {
    if (s[i] != t[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  set<char> suff;
  for (int i = m - 1; i < n; i++) {
    suff.insert(s[i]);
  }

  if (suff.count(t.back())) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
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