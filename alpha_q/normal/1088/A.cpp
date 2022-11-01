#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int x; 

int main() {
  cin >> x;
  for (int a = 1; a <= x; ++a) {
    for (int b = 1; b <= x; ++b) {
      if (a % b == 0 and a * b > x and a / b < x) {
        cout << a << " " << b << '\n';
        return 0;
      }
    }
  }
  cout << "-1\n";
  return 0;
}