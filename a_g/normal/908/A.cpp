#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  string bad = "aeiou13579";
  for (char c: s) {
    for (char d: bad) {
      if (c == d) ans++;
    }
  }
  cout << ans << '\n';
}