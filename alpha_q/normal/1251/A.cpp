#include <bits/stdc++.h>

using namespace std;

int t; string s;

int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    int mask = 0;
    for (int i = 0; i < s.size();) {
      int j = i;
      while (j < s.size() and s[j] == s[i]) ++j;
      if ((j - i) & 1) mask |= 1 << (s[i] - 'a');
      i = j;
    }
    for (int i = 0; i < 26; ++i) if (mask & 1 << i) {
      putchar('a' + i);
    }
    cout << '\n';
  }
  return 0;
}