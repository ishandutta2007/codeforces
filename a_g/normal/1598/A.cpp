#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool win = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] == '1') win = 0;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}