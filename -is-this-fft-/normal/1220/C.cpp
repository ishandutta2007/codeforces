#include <iostream>
#include <string>

using namespace std;

int main () {
  string str;
  cin >> str;

  char curmin = 'z' + 1;
  for (char c : str) {
    if (c <= curmin) {
      cout << "Mike" << '\n';
      curmin = c;
    } else {
      cout << "Ann" << '\n';
    }
  }
}