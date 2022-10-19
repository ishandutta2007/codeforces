#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << (2*count(s.begin(), s.end(), 'B') == s.size() ? "YES\n" : "NO\n");
  }
}