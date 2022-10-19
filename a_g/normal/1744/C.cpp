#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    s += s;
    bool b = 0;
    int time = 0;
    int ans = 0;
    for (char d: s) {
      if (d == c) {
        b = 1;
      }
      if (d == 'g') {
        b = 0;
        ans = max(ans, time);
        time = 0;
      }
      if (b) time++;
    }
    cout << ans << '\n';
  }
}