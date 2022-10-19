#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  if (n % 4 != 2) {
    if (n % 4 == 0) cout << 1;
    else if (n % 4 == 1) cout << 0;
    else if (n % 4 == 3) cout << 2;
    cout << " A\n";
  }
  else cout << "1 B\n";
}