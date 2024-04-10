#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string s, t;
  cin >> s >> t;
  while (!s.empty()) {
    if (t.empty()) return 1;
    if (t.empty() || s.back() != t.back()) {
      s.pop_back();
      if (s.empty()) return 0;
      s.pop_back();
    }
    else {
      s.pop_back();
      t.pop_back();
    }
  }
  return t.empty();
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}