#include <iostream>

using namespace std;

void solve () {
  int a, b;
  cin >> a >> b;

  int ans = (a + b) / 3;
  ans = min(ans, a);
  ans = min(ans, b);
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}