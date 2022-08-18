#include <iostream>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  string t;
  int state = 0;
  for (char c : s) {
    if (state == 0 && c != 'a') {
      state = 1;
    } else if (state == 1 && c == 'a') {
      state = 2;
    }

    if (state == 1) {
      t += c - 1;
    } else {
      t += c;
    }
  }

  if (state == 0) {
    t.back() = 'z';
  }

  cout << t << endl;
}