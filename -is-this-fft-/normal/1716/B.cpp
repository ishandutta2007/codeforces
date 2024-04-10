#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  
  cout << n << '\n';
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << '\n';

    if (i == 0) {
      break;
    }

    swap(arr[i - 1], arr[i]);
  }
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