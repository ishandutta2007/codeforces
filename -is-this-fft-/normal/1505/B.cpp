#include <iostream>

using namespace std;

int dsum (int x) {
  int ans = 0;
  while (x != 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int ddsum (int x) {
  while (x >= 10) {
    x = dsum(x);
  }
  return x;
}

int main () {
  int n;
  cin >> n;

  cout << ddsum(n) << endl;
}