#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n, m;
string s, t;

int main() {
  cin >> n >> m >> s >> t;
  int at = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      at = i;
      break;
    }
  }
  if (at == -1) {
    cout << ((s == t) ? "YES" : "NO") << '\n';
    return 0;
  }
  if (m < n - 1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; s[i] != '*'; ++i) {
    if (s[i] != t[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = n - 1, j = m - 1; s[i] != '*'; --i, --j) {
    if (s[i] != t[j]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}