#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x != 2) {
      ans++;
    }
  }
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