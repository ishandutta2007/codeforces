#include <iostream>

using namespace std;

const int MAX_N = 105;

int arr [MAX_N];

void solve () {
  int n, X;
  cin >> n >> X;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur + arr[i] == X) {
      if (i == n - 1) {
        cout << "NO" << '\n';
        return;
      }

      swap(arr[i], arr[i + 1]);
    }

    cur += arr[i];
  }

  cout << "YES" << '\n';
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