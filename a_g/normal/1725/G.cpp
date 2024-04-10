#include <bits/stdc++.h>
using namespace std;

// (m+1)^2-m^2=2m+1
// (m+2)-2-m^2=4m+4
// good numbers: 3, 5, 7, 8, 9, 11, 12, etc
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "3\n";
  }
  else if (n%3 == 1) {
    cout << 4*(n/3)+4 << '\n';
  }
  else if (n%3 == 2) {
    cout << 4*(n/3)+5 << '\n';
  }
  else {
    cout << 4*(n/3)+3 << '\n';
  }
}