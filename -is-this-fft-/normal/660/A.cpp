#include <iostream>

const int MAX_LEN = 1005;

using namespace std;

int gcd (int a, int b) {
  while (a > 0 && b > 0) {
    a %= b;
    swap(a, b);
  }
  return a + b;
}

int arr [MAX_LEN];
bool ins [MAX_LEN];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 1; i < length; i++) {
    if (gcd(arr[i - 1], arr[i]) != 1) {
      ins[i] = true;
      ans++;
    }
  }

  cout << ans << endl;
  for (int i = 0; i < length; i++) {
    cout << (ins[i] ? "1 " : "") << arr[i] << (i == length - 1 ? '\n' : ' ');
  }
}