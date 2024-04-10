#include <iostream>
#include <string>

using namespace std;

bool all_same (string s) {
  for (int i = 1; i < (int) s.size(); i++) {
    if (s[i] != s[0]) return false;
  }
  return true;
}

bool is_palin (string s) {
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != s[(int) s.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main () {
  string s;
  cin >> s;

  if (is_palin(s)) {
    if (all_same(s)) {
      cout << 0 << endl;
    } else {
      cout << (int) s.size() - 1 << endl;
    }
  } else {
    cout << (int) s.size() << endl;
  }
}