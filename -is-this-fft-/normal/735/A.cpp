#include <iostream>
#include <string>

using namespace std;

int main () {
  int length, jumpl;
  cin >> length >> jumpl;

  string track;
  cin >> track;

  int begin, target;
  for (int i = 0; i < length; i++) {
    if (track[i] == 'G') {
      begin = i;
    } else if (track[i] == 'T') {
      target = i;
    }
  }

  if (begin > target) {
    swap(begin, target);
  }

  if ((target - begin) % jumpl != 0) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = begin; i < target; i += jumpl) {
    if (track[i] == '#') {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}