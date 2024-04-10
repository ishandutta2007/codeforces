#include <iostream>
#include <string>
#include <deque>
using namespace std;

int manhattan (int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

bool query (int r1, int c1, int r2, int c2) {
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  string ans;
  cin >> ans;

  return (ans == "YES");
}

int main () {
  int length;
  cin >> length;

  deque<char> ans1;
  int r = 1, c = 1;
  for (int i = 0; i < length - 1; i++) {
    if (query(r, c + 1, length, length)) {
      c++;
      ans1.push_back('R');
    } else {
      r++;
      ans1.push_back('D');
    }
  }

  deque<char> ans2;
  r = length;
  c = length;
  for (int i = 0; i < length - 1; i++) {
    if (query(1, 1, r - 1, c)) {
      r--;
      ans2.push_front('D');
    } else {
      c--;
      ans2.push_front('R');
    }
  }

  cout << "! ";
  for (char c : ans1) {
    cout << c;
  }
  for (char c : ans2) {
    cout << c;
  }
  cout << endl;
}