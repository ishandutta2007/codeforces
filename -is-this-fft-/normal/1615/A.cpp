#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    sum += x;
  }

  cout << (sum % n != 0) << '\n';
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