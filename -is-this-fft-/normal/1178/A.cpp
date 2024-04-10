#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

int arr [MAX_N];

int main () {
  int length;
  cin >> length;

  int sum = 0, coalsum = 0;
  vector<int> coal;
  for (int i = 1; i <= length; i++) {
    cin >> arr[i];

    if (i == 1 || 2 * arr[i] <= arr[1]) {
      coalsum += arr[i];
      coal.push_back(i);
    }
    sum += arr[i];
  }

  if (2 * coalsum > sum) {
    cout << (int) coal.size() << endl;
    for (int u : coal) {
      cout << u << " ";
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
}