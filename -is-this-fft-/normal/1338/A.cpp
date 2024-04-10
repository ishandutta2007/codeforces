#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int mx = arr[0], maxa = 0;
  for (int i = 0; i < n; i++) {
    maxa = max(maxa, mx - arr[i]);
    mx = max(mx, arr[i]);
  }

  if (maxa == 0) {
    cout << 0 << '\n';
  } else {
    cout << 32 - __builtin_clz(maxa) << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}