#include <bits/stdc++.h>

using namespace std;

void solve () {
  int a, b, c;
  cin >> a >> b >> c;

  int mx = max({a, b, c});
  int mn = min({a, b, c});
  int mid = a ^ b ^ c ^ mx ^ mn;

  if (mx - 1 > mn + mid) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
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