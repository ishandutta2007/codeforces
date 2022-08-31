#include <iostream>
#include <string>

using namespace std;

int main () {
  string num = "";
  for (int i = 1; i <= 1000; i++) {
    num += to_string(i);
  }

  int val;
  cin >> val;
  cout << num[val - 1] << endl;
}