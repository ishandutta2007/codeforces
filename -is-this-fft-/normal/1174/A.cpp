#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e3 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  if (arr[0] == arr[n - 1]) {
    cout << - 1 <<endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}