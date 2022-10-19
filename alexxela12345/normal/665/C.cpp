#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      s[i] = 'a' + (s[i] - 'a' + 1) % 26;
      while (i != n - 1 && s[i] == s[i + 1]) {
        s[i] = 'a' + (s[i] - 'a' + 1) % 26;
      }
    }
  }
  cout << s << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}