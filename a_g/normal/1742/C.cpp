#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    char ans = 'B';
    for (int i = 0; i < 8; i++) {
      string row;
      cin >> row;
      if (row == "RRRRRRRR") ans = 'R';
    }
    cout << ans << '\n';
  }
}