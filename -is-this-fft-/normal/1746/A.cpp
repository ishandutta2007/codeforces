#include <iostream>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  bool all0 = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 1) all0 = false;
  }

  cout << (all0 ? "NO" : "YES") << '\n';
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