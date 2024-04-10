#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int ans = -1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    if (p != i) {
      ans &= p;
    }
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