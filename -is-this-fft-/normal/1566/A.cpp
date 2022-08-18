#include <iostream>

using namespace std;

void solve () {
  int n, S;
  cin >> n >> S;

  n -= (n - 1) / 2;
  cout << S / n << '\n';
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