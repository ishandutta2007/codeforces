#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  for (int i = 2; i <= n + 1; i++) {
    cout << i << " ";
  }
  cout << '\n';
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