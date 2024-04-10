#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int m = count(s.begin(), s.end(), 'M');
    bool ok = (3*m==n);
    int d = 0;
    for (char c: s) {
      if (c == 'T') d++;
      else d--;
      if (d < 0) ok = 0;
    }
    reverse(s.begin(), s.end());
    d = 0;
    for (char c: s) {
      if (c == 'T') d++;
      else d--;
      if (d < 0) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}