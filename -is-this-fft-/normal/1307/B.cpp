#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void solve () {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int mx = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      cout << 1 << '\n';
      return;
    }
    mx = max(mx, arr[i]);
  }

  cout << max(2, (x + mx - 1) / mx) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}