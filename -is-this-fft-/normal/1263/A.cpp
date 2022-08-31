#include <bits/stdc++.h>

using namespace std;

void solve () {
  int a, b, c;
  cin >> a >> b >> c;

  int mx = max({a, b, c});
  int oth = a + b + c - mx;

  if (mx > oth) {
    cout << oth << '\n';
  } else {
    cout << ((a + b + c) / 2) << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}