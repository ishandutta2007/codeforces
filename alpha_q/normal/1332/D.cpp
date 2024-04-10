#include <bits/stdc++.h>

using namespace std;

int k;

int main() {
  cin >> k;
  cout << "3 4\n";
  int a = (1 << 18) - 1, b = (1 << 17) - 1, c = (1 << 18), d = (1 << 17);
  cout << a << " " << b << " " << b << " " << "0\n";
  cout << d << " " << c << " " << b << " " << b - k << '\n';
  cout << a << " " << a << " " << a << " " << b << '\n';
  return 0;
}