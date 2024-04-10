#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr [200005];

int main () {
  int length, target;
  cin >> length >> target;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + length);

  long long ans = 0;
  for (int i = 0; i < length / 2; i++) {
    ans += max(arr[i] - target, 0);
  }
  ans += abs(arr[length / 2] - target);
  for (int i = length / 2 + 1; i < length; i++) {
    ans += max(target - arr[i], 0);
  }
  
  cout << ans << endl;
}