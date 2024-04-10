#include <iostream>
#include <vector>

using namespace std;

int main () {
  int type;
  cin >> type;

  vector<int> nums;
  for (int i = 0; i < 5; i++) {
    char c;
    cin >> c;

    if (i != 2) {
      nums.push_back(c - '0');
    }
  }

  int hr = nums[0] * 10 + nums[1];
  if (type == 12) {
    if (hr == 0) {
      nums[1] = 1;
    } else if (hr > 12) {
      if (nums[1] == 0) {
        nums[0] = 1;
      } else {
        nums[0] = 0;
      }
    }
  } else {
    if (hr > 23) {
      nums[0] = 0;
    }
  }

  int mn = nums[2] * 10 + nums[3];
  if (mn > 59) {
    nums[2] = 0;
  }

  for (int i = 0; i < 2; i++) {
    cout << nums[i];
  }
  cout << ':';
  for (int i = 2; i < 4; i++) {
    cout << nums[i];
  }
  cout << endl;
}