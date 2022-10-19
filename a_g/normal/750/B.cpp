#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int cur = 0;
  bool ok = 1;
  while (n--) {
    string dir;
    int t;
    cin >> t >> dir;
    if (cur == 0 && dir != "South") ok = 0;
    if (cur == 20000 && dir != "North") ok = 0;
    if (dir == "North") {
      cur -= t;
    }
    else if (dir == "South") {
      cur += t;
    }
    if (cur < 0 || cur > 20000) ok = 0;
  }
  if (cur != 0) ok = 0;
  cout << (ok ? "YES" : "NO") << '\n';
}