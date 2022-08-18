#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && arr[i] < 0) {
      arr[i] = -arr[i];
    }
    if (i % 2 == 1 && arr[i] > 0) {
      arr[i] = -arr[i];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}