#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int mx = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    mx = max(mx, x);
    sum += x;
  }

  if (mx > sum - mx) {
    cout << "T" << '\n';
  } else if (sum % 2 == 0) {
    cout << "HL" << '\n';
  } else {
    cout << "T" << '\n';
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