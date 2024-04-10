#include <iostream>

using namespace std;

const int ans [] = {
  0,
  1,
  0,
  0,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  0,
  0,
  1,
  0,
  1,
  0
};

int main () {
  int x;
  cin >> x;

  cout << ans[x] << endl;
}