#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    if (a != b) {
      cout << min(a, b) << '\n';
      continue;
    }
    cout << a-1 << '\n';
  }
}