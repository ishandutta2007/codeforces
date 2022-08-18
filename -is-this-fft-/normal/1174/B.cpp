#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  bool ok = false;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    if (arr[i] % 2 != arr[0] % 2) {
      ok = true;
    }
  }

  if (ok) {
    sort(arr, arr + n);
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}