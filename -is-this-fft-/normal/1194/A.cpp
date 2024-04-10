#include <iostream>

using namespace std;

int main () {
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    int n, x;
    cin >> n >> x;

    cout << 2 * x << '\n';
  }
}