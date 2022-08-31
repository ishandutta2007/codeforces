#include <iostream>

using namespace std;

int sq (int x) {
  return x * x;
}

int main () {
  int x;
  cin >> x;

  cout << 2 - sq(x) << endl;
}