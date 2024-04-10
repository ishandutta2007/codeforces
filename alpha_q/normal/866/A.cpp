#include <bits/stdc++.h>

using namespace std;

int a;

int main() {
  cin >> a;
  if (a & 1) {
    cout << (a + a - 1) << " 2\n1 2 \n";
  } else {
    cout << (a + a - 2) << " 2\n1 2\n";
  }
  return 0;
}