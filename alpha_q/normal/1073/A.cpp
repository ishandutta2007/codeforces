#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n; string s;

int main() {
  cin >> n >> s;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      cout << "YES\n";
      cout << s[i] << s[i + 1] << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}