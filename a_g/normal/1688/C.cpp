#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    char ans = 0;
    for (int i = 0; i <= 2*n; i++) {
      string s;
      cin >> s;
      for (char c: s) {
        ans ^= c;
      }
    }
    cout << ans << '\n';
  }
}