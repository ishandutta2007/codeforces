#include <iostream>

using namespace std;

const int MAX_L = 1005;

int arr [MAX_L];
int length;

int placel (int num) {
  for (int i = 1; i <= length; i++) {
    if (arr[i] == 0) {
      arr[i] = num;
      return i;
    }
    
    if (arr[i] > num) {
      arr[i] = num;
      return i;
    }
  }
}

int placer (int num) {
  for (int i = length; i >= 1; i--) {
    if (arr[i] == 0) {
      arr[i] = num;
      return i;
    }

    if (arr[i] < num) {
      arr[i] = num;
      return i;
    }
  }
}

bool wins () {
  for (int i = 1; i <= length; i++) {
    if (arr[i] == 0) {
      return false;
    }
  }
  return true;
}

int main () {
  int turnc, cst;
  cin >> length >> turnc >> cst;
  while (!wins()) {
    int num;
    cin >> num;
    if (num <= cst / 2) {
      cout << placel(num) << endl;
    } else {
      cout << placer(num) << endl;
    }
  }
}