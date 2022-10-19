#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i+j >= n) break;
      if (s[i+j] != t[j]) break;
      if (j == m-1) return 1;
      for (int k = 1; k < m-j; k++) {
        if (i+j-k < 0) break;
        if (s[i+j-k] != t[j+k]) break;
        if (k == m-j-1) return 1;
      }
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}