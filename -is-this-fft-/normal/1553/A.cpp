#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int ans = n / 10;
  if (n % 10 == 9) {
    ans++;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}