#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  int x = 0;
  int y = 0;
  map<pair<int, int>, int> m;
  m[make_pair(x, y)]++;
  for (char c: s) {
    if (c == 'U') y++;
    if (c == 'D') y--;
    if (c == 'R') x++;
    if (c == 'L') x--;
    ans += m[make_pair(x, y)]++;
  }
  cout << ans << '\n';
}