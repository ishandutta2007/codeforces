#include <iostream>

using namespace std;

const int MAX_N = 300005;

int arr [MAX_N];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  int fc = arr[0];
  int lc = arr[length - 1];
  int ans = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] != fc) {
      ans = max(ans, i);
    }
    if (arr[i] != lc) {
      ans = max(ans, length - 1 - i);
    }
  }
  cout << ans << '\n';
}