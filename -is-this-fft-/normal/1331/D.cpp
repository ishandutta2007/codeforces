#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  char c = s.back();
  c -= '0';

  cout << (int) c % 2 << endl;
}