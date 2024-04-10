#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bool same = true;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[0]) same = false;
  }

  if (same) {
    cout << n << '\n';
  } else {
    cout << 1 << '\n';
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