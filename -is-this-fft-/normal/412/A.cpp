#include <iostream>

const int MAX_LENGTH = 105;

using namespace std;

char arr [MAX_LENGTH];

int main () {
  int length, pos;
  cin >> length >> pos;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  cout << "PRINT " << arr[pos] << '\n';
  if (pos <= length / 2) {
    int cur = pos;
    while (cur > 1) {
      cout << "LEFT\n";
      cur--;

      cout << "PRINT " << arr[cur] << '\n';
    }

    while (cur < pos) {
      cout << "RIGHT\n";
      cur++;
    }

    while (cur < length) {
      cout << "RIGHT\n";
      cur++;

      cout << "PRINT " << arr[cur] << '\n';
    }
  } else {
    int cur = pos;
    
    while (cur < length) {
      cout << "RIGHT\n";
      cur++;

      cout << "PRINT " << arr[cur] << '\n';
    }

    while (cur > pos) {
      cout << "LEFT\n";
      cur--;
    }

    while (cur > 1) {
      cout << "LEFT\n";
      cur--;

      cout << "PRINT " << arr[cur] << '\n';
    }
  }
}