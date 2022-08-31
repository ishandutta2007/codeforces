#include <iostream>
#include <string>

using namespace std;

int main () {
  string str;
  cin >> str;

  if (str == string("0")) {
    cout << 0 << endl;
    return 0;
  }

  int zc = 0;
  for (char c : str) {
    if (c == '0') {
      zc++;
    }
  }

  int len = (int) str.size() - 1;

  if (len == zc && len % 2 == 0) {
    cout << len / 2 << '\n';
  } else {
    cout << len / 2 + 1 << endl;
  }
}