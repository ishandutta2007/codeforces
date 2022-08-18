#include <iostream>

using namespace std;

const int MAX_N = 1005;

int arr [MAX_N][MAX_N];

int main () {
  int length;
  cin >> length;

  int cur = 0;
  for (int i = 0; i < length / 2; i++) {
    for (int j = 0; j < length / 2; j++) {
      arr[i][j] = cur;
      arr[length / 2 + i][j] = cur + 2;
      arr[i][length / 2 + j] = cur + 3;
      arr[length / 2 + i][length / 2 + j] = cur + 1;
      cur += 4;
    }
  }

  for (int i = 0; i < length; i++) {
    int xs = 0;
    for (int j = 0; j < length; j++) {
      cout << arr[i][j] << " ";
      xs ^= arr[i][j];
    }
    cerr << xs << '\n';
    cout << '\n';
  }
}